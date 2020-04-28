//
//  TextTranslateViewController.m
//  Demo
//
//  Created by yiqiwang(王一棋) on 2018/12/6.
//  Copyright © 2018 tencent. All rights reserved.
//

#import "TextTranslateViewController.h"
#import <QTTranslator/QTTranslator.h>

@interface TextTranslateViewController ()

@property (nonatomic, strong) UITextView *searchTextView;
@property (nonatomic, strong) UITextView *resultTextView;
@property (nonatomic, strong) UIButton *searchButton;

@end

@implementation TextTranslateViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self initUI];
    [self setupEvents];
}

- (void)initUI {
    self.view.backgroundColor = UIColor.whiteColor;

    CGRect searchTextViewRect = CGRectMake(20, 90, self.view.bounds.size.width - 80, 40);
    self.searchTextView = [[UITextView alloc] initWithFrame:searchTextViewRect];
    self.searchTextView.layer.borderColor = UIColor.grayColor.CGColor;
    self.searchTextView.layer.borderWidth = 2.0;
    self.searchTextView.layer.cornerRadius = 10;
    [self.view addSubview:self.searchTextView];

    CGRect searchButtonRect = CGRectMake(self.view.bounds.size.width - 55, 90, 50, 50);
    self.searchButton = [[UIButton alloc] initWithFrame:searchButtonRect];
    [self.searchButton setTitle:@"查询" forState:UIControlStateNormal];
    [self.searchButton setTitleColor:UIColor.grayColor forState:UIControlStateNormal];
    [self.view addSubview:self.searchButton];

    CGRect resultTextViewRect = CGRectMake(20, 145, self.view.bounds.size.width - 40, 200);
    self.resultTextView = [[UITextView alloc] initWithFrame:resultTextViewRect];
    self.resultTextView.editable = NO;
    [self.view addSubview:self.resultTextView];
}

- (void)setupEvents {
    [self.searchButton addTarget:self action:@selector(onSearchAction) forControlEvents:UIControlEventTouchUpInside];
}

#pragma mark - Events

- (void)onSearchAction {
    [self startTranslate];
}

#pragma mark -

- (void)startTranslate {
    QTTextTranslateReq *rep = [QTTextTranslateReq new];
    rep.sourceText = self.searchTextView.text;

    // 设置翻译语言对，仅支持 中文 和 其他语种 的翻译
    NSString *langPair = @"";

    // 用法1
    NSString *srcLang = [[NSUserDefaults standardUserDefaults] objectForKey:@"sourceLang"];
    NSString *tgtLang = [[NSUserDefaults standardUserDefaults] objectForKey:@"targetLang"];
    langPair = [NSString stringWithFormat:@"%@|%@", srcLang, tgtLang];

    // 用法2 推荐用法
//    QTLanguagePair *langPair = [[QTLanguagePair alloc] initWithSource:QTLangTypeZh target:QTLangTypeJp];
//    langPair = [langPair reqValue];

    rep.candidateLangPair = langPair;
    rep.enableDic = NO;
    rep.sessionUUID = [[NSUUID UUID] UUIDString];

    [QTTranslateManager.shared translateText:rep
                                    complete:^(QTTextTranslateRsp *rsp)
    {
        dispatch_async(dispatch_get_main_queue(), ^{
            self.resultTextView.text = rsp.targetText;
        });
    }];
}

@end
