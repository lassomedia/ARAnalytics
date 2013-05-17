//
//  ARAnalytics.h
//  Art.sy
//
//  Created by orta therox on 18/12/2012.
//  Copyright (c) 2012 Art.sy. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation
//  files (the "Software"), to deal in the Software without
//  restriction, including without limitation the rights to use,
//  copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following
//  conditions:
//
//  The above copyright notice and this permission notice shall be
//  included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
//  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
//  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

/**
 @class
 ARAnalytics Main Class.

 @abstract
 The primary interface for dealing with in app Analytics.

 @discussion
 Use the ARAnalytics class to set up your analytics provider and track events.

 <pre>

 [ARAnalytics setupWithAnalytics: @{
    ARCrittercismAppID : @"KEY",
    ARKISSMetricsAPIKey : @"KEY",
    ARGoogleAnalyticsID : @"KEY"
 }];

 </pre>

 For more advanced usage, please see the <a
 href="https://github.com/orta/ARAnalytics">ARAnalytics Readme</a>.
 */

@interface ARAnalytics : NSObject <UINavigationControllerDelegate>

/// A global setup analytics API, keys are provided at the bottom of the documentation.
+ (void)setupWithAnalytics:(NSDictionary *)analyticsDictionary;

/// Setup methods for each individual analytics providers
+ (void)setupTestFlightWithAppToken:(NSString *)token;
+ (void)setupCrashlyticsWithAPIKey:(NSString *)key;
+ (void)setupMixpanelWithToken:(NSString *)token;
+ (void)setupMixpanelWithToken:(NSString *)token andHost:(NSString *)host;
+ (void)setupFlurryWithAPIKey:(NSString *)key;
+ (void)setupGoogleAnalyticsWithID:(NSString *)identifier;
+ (void)setupLocalyticsWithAppKey:(NSString *)key;
+ (void)setupKISSMetricsWithAPIKey:(NSString *)key;
+ (void)setupCrittercismWithAppID:(NSString *)appID;
+ (void)setupCountlyWithAppKey:(NSString *)key andHost:(NSString *)host;
+ (void)setupBugsnagWithAPIKey:(NSString *)key;
+ (void)setupHelpshiftWithAppID:(NSString *)appID domainName:(NSString *)domainName apiKey:(NSString *)apiKey;

/// Set a per user property
+ (void)identifyUserwithID:(NSString *)userID andEmailAddress:(NSString *)email __attribute__((deprecated));
+ (void)identifyUserWithID:(NSString *)userID andEmailAddress:(NSString *)email;

+ (void)setUserProperty:(NSString *)property toValue:(NSString *)value;
+ (void)incrementUserProperty:(NSString *)counterName byInt:(int)amount;

/// Submit user events to providers
+ (void)event:(NSString *)event;
+ (void)event:(NSString *)event withProperties:(NSDictionary *)properties;

/// Monitor Navigation changes as page view
+ (void)pageView:(NSString *)pageTitle;
+ (void)monitorNavigationViewController:(UINavigationController *)controller;

/// Let ARAnalytics deal with the timing of an event
+ (void)startTimingEvent:(NSString *)event;
+ (void)finishTimingEvent:(NSString *)event;

@end

/// an NSLog-like command that send to providers
extern void ARLog (NSString *format, ...);

/// Provide keys for the setupWithDictionary
extern const NSString *ARCountlyAppKey;
extern const NSString *ARCountlyHost;
extern const NSString *ARTestFlightAppToken;
extern const NSString *ARCrashlyticsAPIKey;
extern const NSString *ARMixpanelToken;
extern const NSString *ARMixpanelHost;
extern const NSString *ARFlurryAPIKey;
extern const NSString *ARLocalyticsAppKey;
extern const NSString *ARKISSMetricsAPIKey;
extern const NSString *ARBugsnagAPIKey;
extern const NSString *ARCrittercismAppID;
extern const NSString *ARGoogleAnalyticsID;
extern const NSString *ARHelpshiftAppID;
extern const NSString *ARHelpshiftDomainName;
extern const NSString *ARHelpshiftAPIKey;
