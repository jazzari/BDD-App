package io.cucumber.cucumberexpressions;

import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class CucumberExpression implements Expression {
    // Does not include (){} characters because they have special meaning
    private static final Pattern ESCAPE_PATTERN = Pattern.compile("([\\\\^\\[$.|?*+\\]])");
    static final Pattern PARAMETER_PATTERN = Pattern.compile("(\\\\\\\\)?\\{([^}]+)}");
    private static final Pattern OPTIONAL_PATTERN = Pattern.compile("(\\\\\\\\)?\\(([^)]+)\\)");
    private static final Pattern ALTERNATIVE_NON_WHITESPACE_TEXT_REGEXP = Pattern.compile("([^\\s^/]+)((/[^\\s^/]+)+)");
    private static final String DOUBLE_ESCAPE = "\\\\";

    private final List<ParameterType<?>> parameterTypes = new ArrayList<>();
    private final String source;
    private final TreeRegexp treeRegexp;

    public CucumberExpression(String expression, ParameterTypeRegistry parameterTypeRegistry) {
        this.source = expression;

        expression = processEscapes(expression);
        expression = processOptional(expression);
        expression = processAlternation(expression);
        expression = processParameters(expression, parameterTypeRegistry);
        expression = "^" + expression + "$";
        treeRegexp = new TreeRegexp(expression);
    }

    private String processEscapes(String expression) {
        // This will cause explicitly-escaped parentheses to be double-escaped
        return ESCAPE_PATTERN.matcher(expression).replaceAll("\\\\$1");
    }

    private String processAlternation(String expression) {
        Matcher matcher = ALTERNATIVE_NON_WHITESPACE_TEXT_REGEXP.matcher(expression);
        StringBuffer sb = new StringBuffer();
        while (matcher.find()) {
            // replace \/ with /
            // replace / with |
            String replacement = matcher.group(0).replace('/', '|').replaceAll("\\\\\\|", "/");
            matcher.appendReplacement(sb, "(?:" + replacement + ")");
        }
        matcher.appendTail(sb);
        return sb.toString();
    }

    private String processOptional(String expression) {
        Matcher matcher = OPTIONAL_PATTERN.matcher(expression);
        StringBuffer sb = new StringBuffer();
        while (matcher.find()) {
            // look for double-escaped parentheses
            if (DOUBLE_ESCAPE.equals(matcher.group(1))) {
                matcher.appendReplacement(sb, "\\\\(" + matcher.group(2) + "\\\\)");
            } else {
                matcher.appendReplacement(sb, "(?:" + matcher.group(2) + ")?");
            }
        }
        matcher.appendTail(sb);
        return sb.toString();
    }

    private String processParameters(String expression, ParameterTypeRegistry parameterTypeRegistry) {
        Matcher matcher = PARAMETER_PATTERN.matcher(expression);
        StringBuffer sb = new StringBuffer();
        while (matcher.find()) {
            if (DOUBLE_ESCAPE.equals(matcher.group(1))) {
                matcher.appendReplacement(sb, "\\\\{" + matcher.group(2) + "\\\\}");
            } else {
                String typeName = matcher.group(2);
                ParameterType<?> parameterType = parameterTypeRegistry.lookupByTypeName(typeName);
                if (parameterType == null) {
                    throw new UndefinedParameterTypeException(typeName);
                }
                parameterTypes.add(parameterType);
                matcher.appendReplacement(sb, Matcher.quoteReplacement(buildCaptureRegexp(parameterType.getRegexps())));
            }
        }
        matcher.appendTail(sb);
        return sb.toString();
    }

    private String buildCaptureRegexp(List<String> regexps) {
        StringBuilder sb = new StringBuilder("(");

        if (regexps.size() == 1) {
            sb.append(regexps.get(0));
        } else {
            boolean bar = false;
            for (String captureGroupRegexp : regexps) {
                if (bar) sb.append("|");
                sb.append("(?:").append(captureGroupRegexp).append(")");
                bar = true;
            }
        }

        sb.append(")");
        return sb.toString();
    }

    @Override
    public List<Argument<?>> match(String text) {
        return Argument.build(treeRegexp, parameterTypes, text);
    }

    @Override
    public String getSource() {
        return source;
    }

    @Override
    public Pattern getRegexp() {
        return treeRegexp.pattern();
    }
}
