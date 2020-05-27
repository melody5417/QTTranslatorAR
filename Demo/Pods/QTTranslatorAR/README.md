# README


## Requirements
* iOS 9.0+
* Xcode 10.0+

## Installation

通过 CocoaPods 安装，在 podfile 里添加：

```
	pod 'QTTranslatorAR', '~> 2.0'
```
    

## Permission

所需权限，将以下 key 添加到 info.plist 文件中

```
    <key>NSCameraUsageDescription</key>
    <string>申请拍照权限</string>
    
    <key>NSMicrophoneUsageDescription</key>
    <string>申请麦克风权限</string>
    
    <key>NSPhotoLibraryUsageDescription</key>
    <string>申请照片图库权限</string>
    
    <key>NSSpeechRecognitionUsageDescription</key>
    <string>申请语音识别权限</string>
```

## Usage

### 设置参数
* **appId** 填写申请的 appId，与 app 的 bundleId 绑定，用于鉴权，请妥善保管。必须填写

```
QTTranslateManager.shared.appId = @"XXXX"
```

* **networkStatus** 默认采用 All，不建议修改

```
QTTranslateManager.shared.networkSendingStatus = UseNetworkSendingModeAll;
```

* **envMode** 默认Release，调试时设置Debug模式，仅针对内网

```
QTTranslateManager.shared.envMode = QTTranslateEnvDebug;
```

* **enableLog** 默认NO， 调试时打开log
```
QTTranslateManager.shared.enableLog = YES;
```

* **sourceLang** 服务请求的源语言参数，如 zh，en等，具体种类见 QTLanguageDefine 
* **targetLang** 服务请求的目标语言参数，如 zh，en等，具体种类见 QTLanguageDefine

    ```
    // 支持的语言种类
    typedef NS_ENUM(NSInteger, QTLangType) {
        QTLangTypeUnknown = -1,
        QTLangTypeZh      = 0,  // Chinese
        QTLangTypeEn      = 1,  // English
        QTLangTypeJp      = 2,  // Japanese
        QTLangTypeKr      = 3,  // Korean
        QTLangTypeEs      = 4, // 西班牙
        QTLangTypeRu      = 5,  // Russian
        QTLangTypeFr      = 6,  // French
        QTLangTypeDe      = 7,  // German
        QTLangTypeTh      = 8,  // 泰国
        QTLangTypeVn      = 9,  // 越南
        QTLangTypeId      = 10,  // 印度尼西亚
        QTLangTypeMy      = 11, // 马来西亚
        QTLangTypeIt      = 12, // 意大利
        QTLangTypePt      = 13, // 葡萄牙
        QTLangTypeTr      = 14  // 土耳其
    };
    
    // 构建语种参数 如日文
    langAbbrFromType(QTLangTypeJp) // 返回 @"jp"
    
    // 构建candidateLangPair参数 如中日文转换
    QTLanguagePair *langPair = [[QTLanguagePair alloc] initWithSource:QTLangTypeZh target:QTLangTypeJp];
    candidateLangPair = [langPair reqValue];    // 返回 @"zh|jp"
    
    ```

### 文本翻译

**支持语种** 

中文到（英、日、韩、俄、法、德、泰、越、印尼、马来、西班牙、葡萄牙、意大利、土耳其）的互译

```
// 构建请求参数 QTTextTranslateReq
QTTextTranslateReq *rep = [QTTextTranslateReq new];
rep.sessionUUID = [[NSUUID UUID] UUIDString];
rep.sourceText = @"测试文本";

// 设置语言种类参数方式一
// 设置源语言，目标语言，不用设置candidateLangPair
rep.sourceLang = langAbbrFromType(QTLangTypeZh);
rep.targetLang = langAbbrFromType(QTLangTypeEn);

// 设置语言种类参数方式二
// 翻译支持自动识别语言种类 
// 设置candidateLangPair，不指定源语言，目标语言
QTLanguagePair *langPair = [[QTLanguagePair alloc] initWithSource:QTLangTypeZh target:QTLangTypeJp];
rep.candidateLangPair = [langPair reqValue];

// 开始文本请求
[QTTranslateManager.shared translateText:rep complete:^(QTTextTranslateRsp *rsp) {
        // 文本翻译请求回调
        // 处理响应参数 QTTextTranslateRsp
}];
```

### 语音翻译

**支持语种** 

中文到（英、日、韩、俄、法、德、泰、越、印尼、马来、西班牙、葡萄牙、意大利、土耳其）的互译

```
// 初始化语音翻译引擎
QTAudioTranslateManager *manager = [QTAudioTranslateManager shared];
manager.delegate = self;
[manager configure];

// 开始语音翻译
[manager startWithSourceLang:langAbbrFromType(QTLangTypeZh) targetLang:langAbbrFromType(QTLangTypeEn)];

// 结束语音翻译
[manager stop];


// 实现语音翻译引擎代理 QTAudioTranslateManagerDelegate

// 语音翻译已开始
- (void)didStartTranslate;

// 语音翻译已结束
- (void)didStopTranslate;

// 收到语音翻译的识别结果
- (void)didReceiveRecognizingText:(NSString *)text;

// 语音识别错误 在此回调里主动结束本次语音翻译
- (void)didReceiveRecognizeFail:(NSError *)error;

// 收到语音翻译的最终结果
- (void)didReceiveTranslateRsp:(QTTextTranslateRsp *)rsp;

// 收到语音音量数据，可用于绘制波形图
- (void)didReceiveVoicePower:(CGFloat)value;
    
```

### 图片翻译

**支持语种**

图片翻译支持中文到 （英、日、韩、西班牙、法、德、越、马来、意大利、葡萄牙）的互译


```
// 构建请求参数 QTImageTranslateReq
QTImageTranslateReq *rep = [QTImageTranslateReq new];
rep.sessionId = NSUUID.UUID.UUIDString;
rep.sourceImage = [UIImage imageNamed:@"testImage"];

// 设置语言种类参数方式一
// 设置源语言，目标语言，不用设置candidateLangPair
rep.sourceLang = langAbbrFromType(QTLangTypeZh);
rep.targetLang = langAbbrFromType(QTLangTypeEn)";

// 设置语言种类参数方式二
// 翻译支持自动识别语言种类 
// 设置candidateLangPair，不指定源语言，目标语言
QTLanguagePair *langPair = [[QTLanguagePair alloc] initWithSource:QTLangTypeZh target:QTLangTypeJp];
rep.candidateLangPair = [langPair reqValue];

// 开始图片翻译请求
[QTTranslateManager.shared translateImage:rep complete:^(QTImageTranslateRsp * _Nonnull rsp) {
        // 图片翻译请求回调
        // 处理响应参数 QTImageTranslateRsp
}];
```

### TTS

**支持语种** 

中、英、日、韩、俄、法、德、泰、越、印尼、马来、西班牙、葡萄牙、意大利、土耳其

TTS 音频文件存储在 cache 中，文件有7天有效期。

```
__weak __typeof(self)weakSelf = self;
QTTtsServiceReq *req = [QTTtsServiceReq new];
req.sessionUUID = [NSUUID UUID].UUIDString;
req.text = @"测试TTS";
req.lang = QTLangTypeZh;
req.rate = 1.8;
BOOL didPlay = [QTTtsManager.shared readTtsReq:req endBlock:^{
   [weakSelf.playButton stopAnimating];
}];
if (didPlay) {
    [weakSelf.playButton startAnimating];
}
```
### AR翻译

**支持语种** 

AR翻译支持中文到 （英、日、韩、西班牙、法、德、越、马来、意大利、葡萄牙）的互译

```
// 接口

/**
 * 初始化AR翻译引擎
 * @param controller 传入依赖的viewController用来展示
 */
- (instancetype)initWithController:(UIViewController * _Nonnull )controller
                          delegate:(id<QTARTranslateManagerDelegate> _Nullable)delegate;

/**
 * 配置AR翻译引擎
 * @param source 翻译的源语言类型。具体种类见 QTLangType，通过 langAbbrFromType(QTLangType) 方法构造
 * @param target 翻译的目标语言类型。具体种类见 QTLangType，通过 langAbbrFromType(QTLangType) 方法构造
 * AR翻译支持中文到 （英、日、韩、西班牙、法、德、越、马来、意大利、葡萄牙）的互译
 */
- (void)configureWithSource:(NSString *)source target:(NSString *)target;

/**
 * 获取当前视频帧
 */
- (UIImage *)getCurrentFrame;

/**
 * 开始AR翻译引擎
 */
- (void)resume;
/**
 * 暂停AR翻译引擎
 */
- (void)pause;
/**
 * 释放AR翻译引擎
 */
- (void)releaseEngine;
```

```
// 使用
// Property
@property (nonatomic, strong) QTARTranslateManager *manager;

- (void)setup {
	// 初始化AR翻译
	self.manager = [[QTARTranslateManager alloc] initWithController:self delegate:self];
	NSString *sourceLang = langAbbrFromType(QTLangTypeZh);
	NSString *targetLang = langAbbrFromType(QTLangTypeEn);
	[self.manager configureWithSource:sourceLang target:targetLang];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    // 开始AR翻译
    [self.manager resume];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    // 暂停AR翻译
    [self.manager pause];
}

- (void)dealloc {
	// 结束AR翻译并释放资源 一定不要忘记！
    [self.manager releaseEngine];
    self.manager = nil;
}

// 实现 QTARTranslateManagerDelegate 协议，获取状态回调

- (void)didStart {
	// AR翻译开始
}

// QTTranslateARStatusMove,    // 设备移动
// QTTranslateARStatusStable,  // 设备稳定
// QTTranslateARStatusRequest, // 发起AR翻译
// QTTranslateARStatusTrack,   // AR翻译成功，跟踪Marker
// QTTranslateARStatusError,	 // 设备长期稳定且未识别到有效文本,不再进行AR识别
- (void)statusDidChange:(QTTranslateARStatus)status {
	// AR翻译状态
}

- (void)didStop {
	// AR翻译结束
}

```

## History

### 2.0.4
* AR翻译卡顿优化
* 增加获取当前视频帧接口

### 2.0.3
* AR翻译内存泄漏问题优化

### 2.0.2
* AR翻译增加状态回调

### 2.X
* 转为cocoapods分发
* 增加全功能版，在基础版之上支持AR翻译

### 1.3.0 
* 增加日志模块，便于调试，定位问题
* 优化语音翻译模块，完善弱网情况逻辑

### 1.2.2

* 优化注释文档
* websocket增加ping pong
* 语音翻译本地检测10s无有效文本输入的vad功能支持自定义配置
* 增加开发和发布模式切换

### 1.2.0

* **QTAudioTranslateManager** 增加 enableLocalVad 属性
* **QTTranslateManager** 增加 envMode 属性

### 1.1.0

* **QTTextTranslateReq** 增加词典查询 针对内部服务
* **QTTextTranslateRsp** 丰富返回数据信息
* **QTAudioTranslateManager** 移除config方法
* **QTAudioTranslateManager** 修改开始语音翻译方法 改为 startWith:
* **QTAudioTranslateManager** 优化语音翻译返回结果，丰富返回数据信息
