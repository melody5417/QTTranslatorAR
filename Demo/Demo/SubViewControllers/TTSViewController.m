//
//  TTSViewController.m
//  Demo
//
//  Created by yiqiwang(王一棋) on 2019/10/24.
//  Copyright © 2019 tencent. All rights reserved.
//

#import "TTSViewController.h"
#import <QTTranslator/QTTranslator.h>

@interface TTSViewController () <UIPickerViewDataSource, UIPickerViewDelegate>

@property (nonatomic, strong) NSArray *langDataSource;

@end

@implementation TTSViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setupPickerView];
    [self setupImageViews];
}

- (void)setupPickerView {
    self.langDataSource = @[@"zh", @"en", @"jp", @"kr", @"ru", @"fr", @"de", @"th", @"vi", @"id", @"ms", @"es", @"pt", @"it", @"tr"];
    self.langPickerView.delegate = self;
    self.langPickerView.dataSource = self;

    self.textField.returnKeyType = UIReturnKeyDone;
}

- (void)setupImageViews {
    self.image1.animationDuration = 0.5;
    self.image1.image = [UIImage imageNamed:@"black-sound-0"];
    self.image1.animationImages = [self images];

    self.image2.animationDuration = 0.5;
    self.image2.image = [UIImage imageNamed:@"black-sound-0"];
    self.image2.animationImages = [self images];

    self.image3.animationDuration = 0.5;
    self.image3.image = [UIImage imageNamed:@"black-sound-0"];
    self.image3.animationImages = [self images];

    self.image4.animationDuration = 0.5;
    self.image4.image = [UIImage imageNamed:@"black-sound-0"];
    self.image4.animationImages = [self images];

    self.image5.animationDuration = 0.5;
    self.image5.image = [UIImage imageNamed:@"black-sound-0"];
    self.image5.animationImages = [self images];
}

- (NSArray *)images {
    return @[[UIImage imageNamed:@"black-sound-0"],
             [UIImage imageNamed:@"black-sound-1"],
             [UIImage imageNamed:@"black-sound-2"],
             [UIImage imageNamed:@"black-sound-3"],
             [UIImage imageNamed:@"black-sound-4"],
             [UIImage imageNamed:@"black-sound-5"],
             [UIImage imageNamed:@"black-sound-6"]];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    [QTTtsManager.shared stopReading];
}

#pragma mark - Action

- (IBAction)onButton1Action:(id)sender {
    __weak __typeof(self)weakSelf = self;
    QTTtsServiceReq *req = [QTTtsServiceReq new];
    req.sessionUUID = [NSUUID UUID].UUIDString;
    req.text = self.label1.text;
    req.lang = QTLangTypeEn;
    req.voice = QTTtsVoiceAm;
    BOOL didPlay = [QTTtsManager.shared readTtsReq:req endBlock:^{
        [weakSelf.image1 stopAnimating];
    }];
    if (didPlay) {
        [self.image1 startAnimating];
    }
}

- (IBAction)onButton2Action:(id)sender {
    __weak __typeof(self)weakSelf = self;
    QTTtsServiceReq *req = [QTTtsServiceReq new];
    req.sessionUUID = [NSUUID UUID].UUIDString;
    req.text = self.label2.text;
    req.lang = QTLangTypeZh;
    req.rate = 0.8;
    BOOL didPlay = [QTTtsManager.shared readTtsReq:req endBlock:^{
        [weakSelf.image2 stopAnimating];
    }];
    if (didPlay) {
        [self.image2 startAnimating];
    }
}

- (IBAction)onButton3Action:(id)sender {
    __weak __typeof(self)weakSelf = self;
    QTTtsServiceReq *req = [QTTtsServiceReq new];
    req.sessionUUID = [NSUUID UUID].UUIDString;
    req.text = self.label3.text;
    req.lang = QTLangTypeZh;
    req.rate = 0.3;
    BOOL didPlay = [QTTtsManager.shared readTtsReq:req endBlock:^{
        [weakSelf.image3 stopAnimating];
    }];
    if (didPlay) {
        [self.image3 startAnimating];
    }
}

- (IBAction)onButton4Action:(id)sender {
    __weak __typeof(self)weakSelf = self;
    QTTtsServiceReq *req = [QTTtsServiceReq new];
    req.sessionUUID = [NSUUID UUID].UUIDString;
    req.text = self.label4.text;
    req.lang = QTLangTypeZh;
    req.rate = 1.8;
    BOOL didPlay = [QTTtsManager.shared readTtsReq:req endBlock:^{
        [weakSelf.image4 stopAnimating];
    }];
    if (didPlay) {
        [self.image4 startAnimating];
    }
}

- (IBAction)onButton5Action:(id)sender {
    __weak __typeof(self)weakSelf = self;
    QTTtsServiceReq *req = [QTTtsServiceReq new];
    req.sessionUUID = [NSUUID UUID].UUIDString;
    req.text = self.label5.text;
    req.lang = QTLangTypeZh;
    req.voice = QTTtsVoiceBr;
    req.rate = 1.4;
    BOOL didPlay = [QTTtsManager.shared readTtsReq:req endBlock:^{
        [weakSelf.image5 stopAnimating];
    }];
    if (didPlay) {
        [self.image5 startAnimating];
    }
}

- (IBAction)onButton6Action:(id)sender {
    NSInteger index = [self.langPickerView selectedRowInComponent:0];
    NSString *langStr = [self.langDataSource objectAtIndex:index];

    QTTtsServiceReq *req = [QTTtsServiceReq new];
    req.sessionUUID = [NSUUID UUID].UUIDString;
    req.text = self.textField.text;
    req.lang = langTypeFromAbbr(langStr);

    [QTTtsManager.shared readTtsReq:req endBlock:nil];
}

#pragma mark - UIPickerViewDataSource

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView {
    return 1;
}

- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component {
    return self.langDataSource.count;
}

#pragma mark - UIPickerViewDelegate

- (NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component {
    return self.langDataSource[row];
}

@end
