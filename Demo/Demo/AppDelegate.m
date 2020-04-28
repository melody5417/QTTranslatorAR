//
//  AppDelegate.m
//  Demo
//
//  Created by yiqiwang(王一棋) on 2018/12/5.
//  Copyright © 2018 tencent. All rights reserved.
//

#import "AppDelegate.h"
#import "ViewController.h"
#import <QTTranslator/QTTranslator.h>

@interface AppDelegate ()

@property (nonatomic, strong) ViewController *viewController;

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    self.viewController = [[ViewController alloc] init];
    UINavigationController *navController = [[UINavigationController alloc] initWithRootViewController:self.viewController];
    
    self.window = [UIWindow new];
    self.window.frame = UIScreen.mainScreen.bounds;
    self.window.rootViewController = navController;
    [self.window makeKeyAndVisible];

    [self setupTranslate];

    return YES;
}

- (void)setupTranslate {
    // 语种设置见SettingViewController

    // 设置AppId 此处填写业务册自己的appId
    QTTranslateManager.shared.appId = @"b176b3e3-e2b0-42e9-95dd-b67c2a846afe";

    // 开启测试环境 仅针对内网
//    QTTranslateManager.shared.envMode = QTTranslateEnvDebug;

    // 开启日志
    [QTTranslateManager.shared setEnableLog:YES];

    // 配置翻译引擎
    [QTTranslateManager.shared setup];

}

@end
