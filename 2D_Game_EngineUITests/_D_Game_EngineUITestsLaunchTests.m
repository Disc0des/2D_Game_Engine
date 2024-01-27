//
//  _D_Game_EngineUITestsLaunchTests.m
//  2D_Game_EngineUITests
//
//  Created by Dan Hembery on 27/01/2024.
//

#import <XCTest/XCTest.h>

@interface _D_Game_EngineUITestsLaunchTests : XCTestCase

@end

@implementation _D_Game_EngineUITestsLaunchTests

+ (BOOL)runsForEachTargetApplicationUIConfiguration {
    return YES;
}

- (void)setUp {
    self.continueAfterFailure = NO;
}

- (void)testLaunch {
    XCUIApplication *app = [[XCUIApplication alloc] init];
    [app launch];

    // Insert steps here to perform after app launch but before taking a screenshot,
    // such as logging into a test account or navigating somewhere in the app

    XCTAttachment *attachment = [XCTAttachment attachmentWithScreenshot:XCUIScreen.mainScreen.screenshot];
    attachment.name = @"Launch Screen";
    attachment.lifetime = XCTAttachmentLifetimeKeepAlways;
    [self addAttachment:attachment];
}

@end
