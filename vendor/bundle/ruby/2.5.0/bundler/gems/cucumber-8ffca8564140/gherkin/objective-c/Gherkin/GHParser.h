﻿// ------------------------------------------------------------------------------
//  <auto-generated>
//      This code was generated by Berp (http://https://github.com/gasparnagy/berp/).
// 
//      Changes to this file may cause incorrect behavior and will be lost if
//      the code is regenerated.
//  </auto-generated>
// ------------------------------------------------------------------------------


typedef enum    GHTokenType
{
    GHTokenTypeNone,
        GHTokenTypeEOF,
            GHTokenTypeEmpty,
            GHTokenTypeComment,
            GHTokenTypeTagLine,
            GHTokenTypeFeatureLine,
            GHTokenTypeBackgroundLine,
            GHTokenTypeScenarioLine,
            GHTokenTypeScenarioOutlineLine,
            GHTokenTypeExamplesLine,
            GHTokenTypeStepLine,
            GHTokenTypeDocStringSeparator,
            GHTokenTypeTableRow,
            GHTokenTypeLanguage,
            GHTokenTypeOther,
    }               GHTokenType;

typedef enum    GHRuleType
{
    GHRuleTypeNone,
        GHRuleType_EOF, // #EOF
            GHRuleType_Empty, // #Empty
            GHRuleType_Comment, // #Comment
            GHRuleType_TagLine, // #TagLine
            GHRuleType_FeatureLine, // #FeatureLine
            GHRuleType_BackgroundLine, // #BackgroundLine
            GHRuleType_ScenarioLine, // #ScenarioLine
            GHRuleType_ScenarioOutlineLine, // #ScenarioOutlineLine
            GHRuleType_ExamplesLine, // #ExamplesLine
            GHRuleType_StepLine, // #StepLine
            GHRuleType_DocStringSeparator, // #DocStringSeparator
            GHRuleType_TableRow, // #TableRow
            GHRuleType_Language, // #Language
            GHRuleType_Other, // #Other
            GHRuleTypeGherkinDocument, // GherkinDocument! := Feature?
            GHRuleTypeFeature, // Feature! := Feature_Header Background? Scenario_Definition*
            GHRuleTypeFeature_Header, // Feature_Header! := #Language? Tags? #FeatureLine Description_Helper
            GHRuleTypeBackground, // Background! := #BackgroundLine Description_Helper Step*
            GHRuleTypeScenario_Definition, // Scenario_Definition! := Tags? (Scenario | ScenarioOutline)
            GHRuleTypeScenario, // Scenario! := #ScenarioLine Description_Helper Step*
            GHRuleTypeScenarioOutline, // ScenarioOutline! := #ScenarioOutlineLine Description_Helper Step* Examples_Definition*
            GHRuleTypeExamples_Definition, // Examples_Definition! [#Empty|#Comment|#TagLine-&gt;#ExamplesLine] := Tags? Examples
            GHRuleTypeExamples, // Examples! := #ExamplesLine Description_Helper Examples_Table?
            GHRuleTypeExamples_Table, // Examples_Table! := #TableRow #TableRow*
            GHRuleTypeStep, // Step! := #StepLine Step_Arg?
            GHRuleTypeStep_Arg, // Step_Arg := (DataTable | DocString)
            GHRuleTypeDataTable, // DataTable! := #TableRow+
            GHRuleTypeDocString, // DocString! := #DocStringSeparator #Other* #DocStringSeparator
            GHRuleTypeTags, // Tags! := #TagLine+
            GHRuleTypeDescription_Helper, // Description_Helper := #Empty* Description? #Comment*
            GHRuleTypeDescription, // Description! := #Other+
    }               GHRuleType;

#import "GHToken.h"
#import "GHParserException.h"

@protocol GHAstBuilderProtocol <NSObject>

- (void)buildWithToken:(GHToken *)theToken;
- (void)startRuleWithType:(GHRuleType)theRuleType;
- (void)endRuleWithType:(GHRuleType)theRuleType;
- (id)result;
- (void)reset;

@end

@protocol GHTokenScannerProtocol <NSObject>

- (GHToken *)read;

@end

@protocol GHTokenMatcherProtocol <NSObject>

- (BOOL)matchEOFWithToken:(GHToken *)theToken;
- (BOOL)matchEmptyWithToken:(GHToken *)theToken;
- (BOOL)matchCommentWithToken:(GHToken *)theToken;
- (BOOL)matchTagLineWithToken:(GHToken *)theToken;
- (BOOL)matchFeatureLineWithToken:(GHToken *)theToken;
- (BOOL)matchBackgroundLineWithToken:(GHToken *)theToken;
- (BOOL)matchScenarioLineWithToken:(GHToken *)theToken;
- (BOOL)matchScenarioOutlineLineWithToken:(GHToken *)theToken;
- (BOOL)matchExamplesLineWithToken:(GHToken *)theToken;
- (BOOL)matchStepLineWithToken:(GHToken *)theToken;
- (BOOL)matchDocStringSeparatorWithToken:(GHToken *)theToken;
- (BOOL)matchTableRowWithToken:(GHToken *)theToken;
- (BOOL)matchLanguageWithToken:(GHToken *)theToken;
- (BOOL)matchOtherWithToken:(GHToken *)theToken;
- (void)reset;

@end

#import "GHAstBuilder.h"
#import "GHTokenMatcher.h"
#import "GHParserException.h"

@interface GHParserContext : NSObject

@property (nonatomic, strong) id<GHTokenScannerProtocol>            tokenScanner;
@property (nonatomic, strong) id<GHTokenMatcherProtocol>            tokenMatcher;
@property (nonatomic, strong) NSMutableArray<GHToken *>             * tokenQueue;
@property (nonatomic, strong) NSMutableArray<GHParserException *>   * errors;

@end

@interface GHParser : NSObject

@property (nonatomic, assign) BOOL  stopAtFirstError;

- (id)initWithAstBuilder:(id<GHAstBuilderProtocol>)theAstBuilder;
- (id)parseWithTokenScanner:(id<GHTokenScannerProtocol>)theTokenScanner;
- (id)parseWithTokenScanner:(id<GHTokenScannerProtocol>)theTokenScanner tokenMatcher:(id<GHTokenMatcherProtocol>)theTokenMatcher;

@end
