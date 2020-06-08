# -*- encoding: utf-8 -*-
# stub: cucumber-expressions 5.0.18 ruby lib

Gem::Specification.new do |s|
  s.name = "cucumber-expressions".freeze
  s.version = "5.0.18"

  s.required_rubygems_version = Gem::Requirement.new(">= 0".freeze) if s.respond_to? :required_rubygems_version=
  s.require_paths = ["lib".freeze]
  s.authors = ["Aslak Helles\u00F8y".freeze]
  s.date = "2020-06-08"
  s.description = "Cucumber Expressions - a simpler alternative to Regular Expressions".freeze
  s.email = "cukes@googlegroups.com".freeze
  s.files = [".github/ISSUE_TEMPLATE.md".freeze, ".github/PULL_REQUEST_TEMPLATE.md".freeze, ".rspec".freeze, ".rsync".freeze, ".subrepo".freeze, ".travis.yml".freeze, "Gemfile".freeze, "LICENSE".freeze, "Makefile".freeze, "README.md".freeze, "Rakefile".freeze, "cucumber-expressions.gemspec".freeze, "examples.txt".freeze, "lib/cucumber/cucumber_expressions/argument.rb".freeze, "lib/cucumber/cucumber_expressions/combinatorial_generated_expression_factory.rb".freeze, "lib/cucumber/cucumber_expressions/cucumber_expression.rb".freeze, "lib/cucumber/cucumber_expressions/cucumber_expression_generator.rb".freeze, "lib/cucumber/cucumber_expressions/errors.rb".freeze, "lib/cucumber/cucumber_expressions/generated_expression.rb".freeze, "lib/cucumber/cucumber_expressions/group.rb".freeze, "lib/cucumber/cucumber_expressions/group_builder.rb".freeze, "lib/cucumber/cucumber_expressions/parameter_type.rb".freeze, "lib/cucumber/cucumber_expressions/parameter_type_matcher.rb".freeze, "lib/cucumber/cucumber_expressions/parameter_type_registry.rb".freeze, "lib/cucumber/cucumber_expressions/regular_expression.rb".freeze, "lib/cucumber/cucumber_expressions/tree_regexp.rb".freeze, "spec/capture_warnings.rb".freeze, "spec/coverage.rb".freeze, "spec/cucumber/cucumber_expressions/combinatorial_generated_expression_factory_test.rb".freeze, "spec/cucumber/cucumber_expressions/cucumber_expression_generator_spec.rb".freeze, "spec/cucumber/cucumber_expressions/cucumber_expression_regexp_spec.rb".freeze, "spec/cucumber/cucumber_expressions/cucumber_expression_spec.rb".freeze, "spec/cucumber/cucumber_expressions/custom_parameter_type_spec.rb".freeze, "spec/cucumber/cucumber_expressions/expression_examples_spec.rb".freeze, "spec/cucumber/cucumber_expressions/parameter_type_registry_spec.rb".freeze, "spec/cucumber/cucumber_expressions/parameter_type_spec.rb".freeze, "spec/cucumber/cucumber_expressions/regular_expression_spec.rb".freeze, "spec/cucumber/cucumber_expressions/tree_regexp_spec.rb".freeze]
  s.homepage = "https://github.com/cucumber/cucumber-expressions-ruby#readme".freeze
  s.licenses = ["MIT".freeze]
  s.rdoc_options = ["--charset=UTF-8".freeze]
  s.required_ruby_version = Gem::Requirement.new(">= 1.9.3".freeze)
  s.rubygems_version = "3.1.4".freeze
  s.summary = "cucumber-expressions-5.0.18".freeze
  s.test_files = ["spec/capture_warnings.rb".freeze, "spec/coverage.rb".freeze, "spec/cucumber/cucumber_expressions/combinatorial_generated_expression_factory_test.rb".freeze, "spec/cucumber/cucumber_expressions/cucumber_expression_generator_spec.rb".freeze, "spec/cucumber/cucumber_expressions/cucumber_expression_regexp_spec.rb".freeze, "spec/cucumber/cucumber_expressions/cucumber_expression_spec.rb".freeze, "spec/cucumber/cucumber_expressions/custom_parameter_type_spec.rb".freeze, "spec/cucumber/cucumber_expressions/expression_examples_spec.rb".freeze, "spec/cucumber/cucumber_expressions/parameter_type_registry_spec.rb".freeze, "spec/cucumber/cucumber_expressions/parameter_type_spec.rb".freeze, "spec/cucumber/cucumber_expressions/regular_expression_spec.rb".freeze, "spec/cucumber/cucumber_expressions/tree_regexp_spec.rb".freeze]

  s.installed_by_version = "3.1.4" if s.respond_to? :installed_by_version

  if s.respond_to? :specification_version then
    s.specification_version = 4
  end

  if s.respond_to? :add_runtime_dependency then
    s.add_development_dependency(%q<bundler>.freeze, [">= 0"])
    s.add_development_dependency(%q<rake>.freeze, ["~> 12.3"])
    s.add_development_dependency(%q<rspec>.freeze, ["~> 3.7"])
    s.add_development_dependency(%q<coveralls>.freeze, [">= 0"])
  else
    s.add_dependency(%q<bundler>.freeze, [">= 0"])
    s.add_dependency(%q<rake>.freeze, ["~> 12.3"])
    s.add_dependency(%q<rspec>.freeze, ["~> 3.7"])
    s.add_dependency(%q<coveralls>.freeze, [">= 0"])
  end
end
