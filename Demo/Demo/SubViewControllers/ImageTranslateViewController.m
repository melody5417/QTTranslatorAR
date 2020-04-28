//
//  ImageTranslateViewController.m
//  Demo
//
//  Created by yiqiwang(王一棋) on 2018/12/7.
//  Copyright © 2018 tencent. All rights reserved.
//

#import "ImageTranslateViewController.h"
#import <Photos/Photos.h>
#import <QTTranslator/QTTranslator.h>

@interface ImageTranslateViewController () <UINavigationControllerDelegate, UIImagePickerControllerDelegate>

@property (nonatomic, strong) UIImageView *imageView;
@property (nonatomic, strong) UIImage *sourceImage;

@end

@implementation ImageTranslateViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self initUI];
}

- (void)initUI {
    self.view.backgroundColor = UIColor.whiteColor;

    self.imageView = [[UIImageView alloc] initWithFrame:self.view.bounds];
    self.imageView.contentMode = UIViewContentModeScaleAspectFit;
    [self.view addSubview:self.imageView];

    UIBarButtonItem *albumItem = [[UIBarButtonItem alloc] initWithTitle:@"相册" style:UIBarButtonItemStyleDone target:self action:@selector(onClickAlbum)];
    self.navigationItem.rightBarButtonItems = @[albumItem];
}

#pragma mark - Events

- (void)onClickAlbum {
    switch ([PHPhotoLibrary authorizationStatus]) {
        case PHAuthorizationStatusAuthorized:
        {
            UIImagePickerController *vc = [[UIImagePickerController alloc] init];
            vc.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
            vc.delegate = self;
            [self presentViewController:vc animated:YES completion:^{
            }];
        }
            break;

        case PHAuthorizationStatusNotDetermined:
        {
            __weak __typeof(self)weakSelf = self;
            [PHPhotoLibrary requestAuthorization:^(PHAuthorizationStatus status) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    [weakSelf onClickAlbum];
                });
            }];
        }
            break;

        default:
            NSLog(@"Album permission is denied");
    }
}

#pragma mark - UIImagePickerControllerDelegate

- (void)imagePickerController:(UIImagePickerController *)picker
didFinishPickingMediaWithInfo:(NSDictionary<UIImagePickerControllerInfoKey, id> *)info {
    [picker dismissViewControllerAnimated:NO completion:nil];
    UIImage *imagePicked = [info objectForKey:@"UIImagePickerControllerOriginalImage"];
    self.sourceImage = imagePicked;
}

- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker {
    [picker dismissViewControllerAnimated:NO completion:nil];
}

#pragma mark - Setter

- (void)setSourceImage:(UIImage *)sourceImage {
    _sourceImage = sourceImage;

    NSString *srcLang = [[NSUserDefaults standardUserDefaults] objectForKey:@"sourceLang"];
    NSString *tgtLang = [[NSUserDefaults standardUserDefaults] objectForKey:@"targetLang"];
    NSString *langPair = [NSString stringWithFormat:@"%@|%@", srcLang, tgtLang];

    self.imageView.image = self.sourceImage;
    QTImageTranslateReq *rep = [QTImageTranslateReq new];
    rep.sessionId = NSUUID.UUID.UUIDString;
    rep.sourceImage = self.sourceImage;
    rep.sourceLang = srcLang;
    rep.targetLang = tgtLang;
    rep.candidateLangPair = langPair;

    [QTTranslateManager.shared translateImage:rep
                                     complete:^(QTImageTranslateRsp * _Nonnull rsp)
    {
        UIImage *ocrImage = rsp.targetImage;
        self.imageView.image = ocrImage;
    }];
}

@end
