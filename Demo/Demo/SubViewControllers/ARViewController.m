//
//  ARViewController.m
//  Demo
//
//  Created by yiqiwang(王一棋) on 2019/1/28.
//  Copyright © 2019 tencent. All rights reserved.
//

#import "ARViewController.h"
#import <QTTranslator/QTTranslator.h>

@interface ARViewController () <QTARTranslateManagerDelegate>

@property (nonatomic, strong) QTARTranslateManager *manager;

@end

@implementation ARViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setup];
    [self initUI];
}

- (void)setup {
    NSString *srcLang = [[NSUserDefaults standardUserDefaults] objectForKey:@"sourceLang"];
    NSString *tgtLang = [[NSUserDefaults standardUserDefaults] objectForKey:@"targetLang"];

    self.manager = [[QTARTranslateManager alloc] initWithController:self delegate:self];
    [self.manager configureWithSource:srcLang target:tgtLang];
}

- (void)initUI {
    self.view.backgroundColor = UIColor.whiteColor;

}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];

    [self.manager resume];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];

    [self.manager pause];
}

- (void)dealloc {
    [self.manager releaseEngine];
    self.manager = nil;
}

#pragma mark - QTARTranslateManagerDelegate

- (void)didStart {
    NSLog(@"%s", __FUNCTION__);
}

- (void)statusDidChange:(QTTranslateARStatus)status {
    NSLog(@"%s %@", __FUNCTION__, @(status));
}

- (void)didStop {
    NSLog(@"%s", __FUNCTION__);
}
@end
