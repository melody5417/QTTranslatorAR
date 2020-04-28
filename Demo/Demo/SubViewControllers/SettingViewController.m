//
//  SettingViewController.m
//  Demo
//
//  Created by yiqiwang(王一棋) on 2019/9/20.
//  Copyright © 2019 tencent. All rights reserved.
//

#import "SettingViewController.h"
#import <QTTranslator/QTTranslator.h>

@interface SettingViewController () <UIPickerViewDataSource, UIPickerViewDelegate>

@property (weak, nonatomic) IBOutlet UIPickerView *sourceLangPickerView;
@property (weak, nonatomic) IBOutlet UIPickerView *targetLangPickerView;

@property (nonatomic, strong) NSArray *sourceLangDataSource;
@property (nonatomic, strong) NSArray *targetLangDataSource;

@end

@implementation SettingViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.sourceLangDataSource = @[@"zh", @"en", @"jp", @"kr", @"ru", @"fr", @"de", @"th", @"vi", @"id", @"ms", @"es", @"pt", @"it", @"tr"];
    self.targetLangDataSource = @[@"zh", @"en", @"jp", @"kr", @"ru", @"fr", @"de", @"th", @"vi", @"id", @"ms", @"es", @"pt", @"it", @"tr"];

    self.sourceLangPickerView.delegate = self;
    self.sourceLangPickerView.dataSource = self;

    self.targetLangPickerView.delegate = self;
    self.targetLangPickerView.dataSource = self;
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];

    [self configDefaultParams];

    NSString *srcLang = [[NSUserDefaults standardUserDefaults] objectForKey:@"sourceLang"];
    NSInteger srcLangIndex = [self.sourceLangDataSource indexOfObject:srcLang];
    [self.sourceLangPickerView selectRow:srcLangIndex inComponent:0 animated:NO];

    NSString *tgtLang = [[NSUserDefaults standardUserDefaults] objectForKey:@"targetLang"];
    NSInteger tgtLangIndex = [self.targetLangDataSource indexOfObject:tgtLang];
    [self.targetLangPickerView selectRow:tgtLangIndex inComponent:0 animated:NO];
}

#pragma mark - Config default params

- (void)configDefaultParams {
    if (![[NSUserDefaults standardUserDefaults] objectForKey:@"sourceLang"]) {
        [[NSUserDefaults standardUserDefaults] setObject:@"zh" forKey:@"sourceLang"];
    }
    if (![[NSUserDefaults standardUserDefaults] objectForKey:@"targetLang"]) {
        [[NSUserDefaults standardUserDefaults] setObject:@"en" forKey:@"targetLang"];
    }
    [[NSUserDefaults standardUserDefaults] synchronize];
}

#pragma mark - Action

- (IBAction)saveAction:(UIButton *)sender {
    NSInteger seletedSrcLangIndex = [self.sourceLangPickerView selectedRowInComponent:0];
    NSString *sourceLang = self.sourceLangDataSource[seletedSrcLangIndex];
    [[NSUserDefaults standardUserDefaults] setObject:sourceLang forKey:@"sourceLang"];

    NSInteger seletedTgtLangIndex = [self.targetLangPickerView selectedRowInComponent:0];
    NSString *targetLang = self.targetLangDataSource[seletedTgtLangIndex];
    [[NSUserDefaults standardUserDefaults] setObject:targetLang forKey:@"targetLang"];

    [[NSUserDefaults standardUserDefaults] synchronize];

    [self.navigationController popViewControllerAnimated:YES];
}

#pragma mark - UIPickerViewDataSource

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView {
    return 1;
}

- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component {
    if (pickerView == self.sourceLangPickerView) {
        return self.sourceLangDataSource.count;
    } else if (pickerView == self.targetLangPickerView) {
        return self.targetLangDataSource.count;
    }
    return 0;
}

#pragma mark - UIPickerViewDelegate

- (NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component {
    if (pickerView == self.sourceLangPickerView) {
        return self.sourceLangDataSource[row];
    } else if (pickerView == self.targetLangPickerView) {
        return self.targetLangDataSource[row];
    }
    return @"";
}

@end
