//
//  AppDelegate.m
//  MoreiTunes
//
//  Created by Dwang on 2018/1/16.
//  Copyright © 2018年 CoderDwang. All rights reserved.
//

#import "AppDelegate.h"
#import "MTBaseNavigationController.h"
#import "MTAccountViewController.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [self networkingConfig];
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    self.window.rootViewController = [[MTBaseNavigationController alloc] initWithRootViewController:[[MTAccountViewController alloc] init]];
    [self.window makeKeyAndVisible];
    return YES;
}

- (void)networkingConfig {
    [DWNetworking setConfigRequestType:DWRequestTypeJSON responseType:DWResponseTypeJSON];
    [DWNetworking setHttpHeaderConfig:@{@"Connection":@"keep-alive",
                                        @"X-Apple-Widget-Key":@"e0b80c3bf78523bfe80974d320935bfa30add02e1bff88ec2166c6bd5a706c42",
                                        @"Content-Type":@"application/json",
                                        @"Accept":@"application/json, text/javascript, */*; q=0.01",
                                        @"X-Requested-With":@"XMLHttpRequest",
                                        @"Referer":@"https://idmsa.apple.com/appleauth/auth/signin?widgetKey=e0b80c3bf78523bfe80974d320935bfa30add02e1bff88ec2166c6bd5a706c42&widgetDomain=https://itunesconnect.apple.com:443&font=sf",
                                        }];
}

@end
