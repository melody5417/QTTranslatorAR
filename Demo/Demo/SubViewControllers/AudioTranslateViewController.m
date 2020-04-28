//
//  AudioTranslateViewController.m
//  Demo
//
//  Created by yiqiwang(王一棋) on 2019/2/27.
//  Copyright © 2019 tencent. All rights reserved.
//

#import "AudioTranslateViewController.h"
#import <QTTranslator/QTTranslator.h>

@interface AudioTranslateViewController () <QTAudioTranslateManagerDelegate>

@property (nonatomic, strong) QTAudioTranslateManager *manager;
@property (nonatomic, strong) UIButton *controlButton;
@property (nonatomic, strong) UITextView *textView;
@property (nonatomic, strong) UITextView *targetTextView;
@property (nonatomic, getter=isTranslating) BOOL translating;

@end

@implementation AudioTranslateViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setup];
    [self initUI];

    self.translating = NO;
}

- (void)setup {
    self.manager = [QTAudioTranslateManager shared];
    self.manager.delegate = self;
}

- (void)initUI {
    self.view.backgroundColor = UIColor.whiteColor;

    [self.controlButton addTarget:self action:@selector(onControlAction) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.controlButton];

    [self.view addSubview:self.textView];

    [self.view addSubview:self.targetTextView];
}

- (void)onControlAction {
    if (self.isTranslating) {
        [self.manager stop];
    } else {
        self.textView.text = nil;
        self.targetTextView.text = nil;

        QTAudioTranslateReq *rep = [QTAudioTranslateReq new];
        rep.sessionUUID = [NSUUID UUID].UUIDString;
        rep.sourceLang = [[NSUserDefaults standardUserDefaults] objectForKey:@"sourceLang"];
        rep.targetLang = [[NSUserDefaults standardUserDefaults] objectForKey:@"targetLang"];
        rep.enableDic = YES;
        BOOL success = [self.manager startWith:rep];
        if (!success) {
            NSLog(@"开启语音翻译不成功");
        }
    }
}

#pragma mark - QTAudioTranslateManagerDelegate

- (void)didStartTranslate {
    NSLog(@"%s", __FUNCTION__);
    self.translating = YES;
}

- (void)didStopTranslate {
    NSLog(@"%s", __FUNCTION__);
    self.translating = NO;
}

- (void)didReceiveRecognizeFail:(NSError *)error {
    self.translating = NO;
    [self.manager stop];
}

- (void)didReceiveRecognizingText:(NSString *)text {
    self.textView.text = text;
}

- (void)didReceiveTranslateRsp:(QTAudioTranslateRsp *)rsp {
    if (rsp.translateRsp.errCode != 0) {
        NSLog(@"Error: errCode:%d errMsg:%@", rsp.translateRsp.errCode, rsp.translateRsp.errMsg);
        return;
    }
    self.targetTextView.text = rsp.translateRsp.targetText;
}

- (void)didReceiveVoicePower:(CGFloat)value {

}

#pragma mark - Property

- (void)setTranslating:(BOOL)translating {
    if (translating) {
        [self.controlButton setTitle:@"语音翻译中" forState:UIControlStateNormal];
    } else {
        [self.controlButton setTitle:@"开始语音翻译" forState:UIControlStateNormal];
    }
    _translating = translating;
}

- (UIButton *)controlButton {
    if (!_controlButton) {
        _controlButton = [[UIButton alloc] initWithFrame:CGRectMake(120, 80, 120, 48)];
        [_controlButton setTitleColor:UIColor.blackColor forState:UIControlStateNormal];
        _controlButton.layer.cornerRadius = 10.0;
        _controlButton.layer.borderColor = UIColor.grayColor.CGColor;
        _controlButton.layer.borderWidth = 2.0;
    }
    return _controlButton;
}

- (UITextView *)textView {
    if (!_textView) {
        _textView = [[UITextView alloc] initWithFrame:CGRectMake(40, 160, 350, 200)];
        _textView.editable = NO;
    }
    return _textView;
}

- (UITextView *)targetTextView {
    if (!_targetTextView) {
        _targetTextView = [[UITextView alloc] initWithFrame:CGRectMake(40, 410, 350, 200)];
        _targetTextView.editable = NO;
    }
    return _targetTextView;
}

@end
