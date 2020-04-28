//
//  ViewController.m
//  Demo
//
//  Created by yiqiwang(王一棋) on 2018/12/5.
//  Copyright © 2018 tencent. All rights reserved.
//

#import "ViewController.h"
#import "TextTranslateViewController.h"
#import "ImageTranslateViewController.h"
#import "AudioTranslateViewController.h"
#import "SettingViewController.h"
#import "TTSViewController.h"
#import "ARViewController.h"


#define TableViewCellIdentifier @"TableViewCellIdentifier"

@interface ViewController () <UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) NSArray *items;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self initUI];
    [self initData];
}


- (void)initUI {
    self.title = @"QTTranslator";
    self.tableView = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStyleGrouped];
    self.tableView.dataSource = self;
    self.tableView.delegate = self;
    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:TableViewCellIdentifier];
    [self.view addSubview:self.tableView];
}

- (void)initData {
    self.items = @[@"设置语言对", @"文本翻译", @"语音翻译", @"图片翻译", @"TTS", @"AR翻译"];
}

#pragma mark - UITableViewDelegate

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 44;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    NSString *title = self.items[indexPath.item];
    if ([title isEqualToString:@"文本翻译"]) {
        TextTranslateViewController *vc = [TextTranslateViewController new];
        vc.title = title;
        [self.navigationController pushViewController:vc animated:YES];
    }
    else if ([title isEqualToString:@"图片翻译"]) {
        ImageTranslateViewController *vc = [ImageTranslateViewController new];
        vc.title = title;
        [self.navigationController pushViewController:vc animated:YES];
    }
    else if ([title isEqualToString:@"语音翻译"]) {
        AudioTranslateViewController *vc = [AudioTranslateViewController new];
        vc.title = title;
        [self.navigationController pushViewController:vc animated:YES];
    }
    else if ([title isEqualToString:@"设置语言对"]) {
        SettingViewController *vc = [SettingViewController new];
        vc.title = title;
        [self.navigationController pushViewController:vc animated:YES];
    }
    else if ([title isEqualToString:@"TTS"]) {
        TTSViewController *vc = [TTSViewController new];
        vc.title = title;
        [self.navigationController pushViewController:vc animated:YES];
    }
    else if ([title isEqualToString:@"AR翻译"]) {
        ARViewController *vc = [ARViewController new];
        vc.title = title;
        [self.navigationController pushViewController:vc animated:YES];
    }

    [tableView deselectRowAtIndexPath:indexPath animated:NO];
}

#pragma mark - UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.items.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:TableViewCellIdentifier];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:TableViewCellIdentifier];
    }
    cell.textLabel.text = self.items[indexPath.item];
    return cell;
}

@end
