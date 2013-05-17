//
//  ARAnalyticalProvider.h
//  Art.sy
//
//  Created by orta therox on 18/12/2012.
//  Copyright (c) 2012 Art.sy. All rights reserved.
//

@interface ARAnalyticalProvider : NSObject

/// Init
- (id)initWithIdentifier:(NSString *)identifier;

/// Set a per user property
- (void)identifyUserWithID:(NSString *)userID andEmailAddress:(NSString *)email;
- (void)setUserProperty:(NSString *)property toValue:(NSString *)value;

/// Submit user events
- (void)event:(NSString *)event withProperties:(NSDictionary *)properties;
- (void)incrementUserProperty:(NSString *)counterName byInt:(NSNumber *)amount;

/// Monitor Navigation changes as page view
- (void)monitorNavigationViewController:(UINavigationController *)controller;

/// Submit an event with a time interval
- (void)logTimingEvent:(NSString *)event withInterval:(NSNumber *)interval;

/// Pass a specific event for showing a page
- (void)didShowNewPageView:(NSString *)pageTitle;

/// Submit a string to the provider's logging system
- (void)remoteLog:(NSString *)parsedString;

@end