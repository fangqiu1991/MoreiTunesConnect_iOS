//
//  FanYiSDK.h
//  FanYiSDK
//
//  Created by 白静 on 11/18/16.
//  Copyright © 2016 网易有道. All rights reserved.
//

#import <Foundation/Foundation.h>
@class YDTranslate;
@class YDTranslateRequest;
@class YDTranslateParameters;


#pragma mark - 在线查词
typedef void(^YDTranslateRequestHandler)(YDTranslateRequest *request,
                                         YDTranslate *translte,
                                         NSError *error) ;

@interface YDTranslateRequest : NSObject

@property (nonatomic, strong) YDTranslateParameters *translateParameters;
@property (nonatomic, strong) NSArray *supportLanguages;

+ (YDTranslateRequest *)request;

//查询
- (void)lookup:(NSString *) input WithCompletionHandler:(YDTranslateRequestHandler)handler;
//词库初始化，词库放工程中
- (BOOL) initOffline;
//词库初始化，指定词库目录
- (BOOL) initOfflineWithPath:(NSString *)path;
@end

@class CLLocation;

/**
 * The `YDTranslateParameters` class is used to attach targeting information to
 * `YDTranslateRequest` objects.
 */

@interface YDTranslateParameters : NSObject

typedef NS_ENUM(NSInteger, YDLanguageType) {
    YDLanguageTypeAuto = 0,
    YDLanguageTypeChinese, //中文
    YDLanguageTypeEnglish, //英文
    YDLanguageTypeJapanese, //日文
    YDLanguageTypeKorean, //韩文
    YDLanguageTypeFrench, //法文
    YDLanguageTypeRussian, //俄文
    YDLanguageTypePortuguese, //葡萄牙文
    YDLanguageTypeSpanish, //西班牙文
};

/** @name Creating a Targeting Object */

/**
 * Creates and returns an empty YDTranslateParameters object.
 *
 * @return A newly initialized YDTranslateParameters object.
 */
+ (YDTranslateParameters *)targeting;

@property (nonatomic, copy) NSString *source;

@property (nonatomic, assign) YDLanguageType from;

@property (nonatomic, assign) YDLanguageType to;

@property (nonatomic, assign) BOOL offLine;

@end

@interface YDTranslate : NSObject

@property (retain,nonatomic)NSString *query;
@property (retain,nonatomic)NSString *usPhonetic;
@property (retain,nonatomic)NSString *ukPhonetic;
@property (retain,nonatomic)NSString *phonetic;

@property (retain,nonatomic)NSArray *translation;
@property (retain,nonatomic)NSArray *explains;
@property (retain,nonatomic)NSArray *webExplains;

@property (retain,nonatomic)NSString *from;
@property (retain,nonatomic)NSString *to;
@property (retain,nonatomic)NSString *l; //针对国内请求，服务器新增l字段（查询from和to）
@property (retain,nonatomic)NSDictionary *webdict;//针对海外请求，服务器新增webdict字段（词典海外web页面）
@property (retain,nonatomic)NSDictionary *dict;
@property (retain,nonatomic)NSString *tspeakurl;
@property (retain,nonatomic)NSString *speakurl;

@property (assign,atomic)int errorCodes;

- (void)openMore;
- (void)formData;

@end

@interface YDWebExplain : NSObject

@property (retain,nonatomic)NSArray *value;
@property (retain,nonatomic)NSString *key;

- (void)formData:(NSDictionary *) dict;
@end




#pragma mark - 离线查词
@class YDTranslate;
@class YDWordOfflineTranslate;

typedef void(^YDWordOfflineTranslateHandler)(YDWordOfflineTranslate *request,
                                             YDTranslate *translte,
                                             NSError *error) ;

@interface YDWordOfflineTranslate : NSObject


+ (YDWordOfflineTranslate *)request;

//查询
- (void)lookup:(NSString *) input WithCompletionHandler:(YDWordOfflineTranslateHandler)handler;
//词库初始化，词库放工程中
- (BOOL) initOffline;
//词库初始化，指定词库目录
- (BOOL) initOfflineWithPath:(NSString *)path;
@end


#pragma mark - 全局设置
@interface YDTranslateInstance : NSObject

+ (YDTranslateInstance*)sharedInstance;

@property (nonatomic, copy) NSString *appKey;
@property (nonatomic, assign) BOOL isHaiWai;
@property (nonatomic, assign) BOOL isTestMode;
@end



#pragma mark - 汉语词典
@class YDTranslate;
@class YDHanyucidianOfflineTranslate;

typedef void(^YDHanyucidianOfflineTranslateHandler)(YDHanyucidianOfflineTranslate *request,
                                                    NSArray *translte,
                                                    NSError *error) ;

@interface YDHanyucidianOfflineTranslate : NSObject


+ (YDHanyucidianOfflineTranslate *)request;

//查询
- (void)lookup:(NSString *)input WithCompletionHandler:(YDHanyucidianOfflineTranslateHandler)handler;
//词库初始化，指定词库目录
- (BOOL) initOfflineWithPath:(NSString *)path;

@end


@interface YDChDictMeans : NSObject

@property (retain,nonatomic)NSArray *examLines;
@property (retain,nonatomic)NSString *translate;

@end

@interface YDChDictTranslate : NSObject

@property (retain,nonatomic)NSString *query;
@property (retain,nonatomic)NSString *phonetic;

@property (retain,nonatomic)NSArray *translations;

@property (assign,atomic)int errorCodes;

- (void)openMore;
@end

@interface YDExamLine : NSObject

@property (nonatomic, assign)BOOL highlight;
@property (retain,nonatomic)NSString *text;

@end



#pragma mark - 离线句子翻译
@class YDTranslate;
@class YDSentenceOfflineTranslate;

typedef void(^YDSentenceOfflineTranslateHandler)(YDSentenceOfflineTranslate *request,
                                                 YDTranslate *translte,
                                                 NSError *error) ;

@interface YDSentenceOfflineTranslate : NSObject


+ (YDSentenceOfflineTranslate *)request;

//查询
- (void)lookup:(NSString *) input WithCompletionHandler:(YDSentenceOfflineTranslateHandler)handler;
//词库初始化，指定词库目录
- (BOOL) initOfflineSenWithPath:(NSString *)path;
@end

#pragma mark - 在线语音翻译
@class YDSpeechOnlineParam, YDSpeechResult, YDSpeechOnlineRequest;

typedef void(^YDSpeechOnlineRequestHandler)(YDSpeechOnlineRequest *request,YDSpeechResult *result, NSError *error) ;

@interface YDSpeechOnlineRequest : NSObject
@property (nonatomic, strong) YDSpeechOnlineParam *param;
+ (instancetype)request;
//查询
- (void)lookup:(NSString *)input WithCompletionHandler:(YDSpeechOnlineRequestHandler)handler;
@end

@interface YDSpeechResult : NSObject
/* 翻译结果发音地址，翻译成功一定存在 */
@property (nonatomic, copy) NSString *tSpeakUrl;
/* 翻译结果错误码，一定存在 */
@property (nonatomic, copy) NSString *errorCode;
/* 源语言文本，翻译成功一定存在 */
@property (nonatomic, copy) NSString *query;
/* 翻译结果，翻译成功一定存在 */
@property (nonatomic, strong) NSArray *translation;
/* 词典deeplink */
@property (nonatomic, strong) NSDictionary *dict;
/* 词典web deeplink */
@property (nonatomic, strong) NSDictionary *webdict;
/* 源语言发音地址，翻译成功一定存在 */
@property (nonatomic, copy) NSString *speakUrl;

+ (instancetype)initWithDict:(NSDictionary *)info;
@end

@interface YDSpeechOnlineParam : NSObject
/* 源语言 */
@property (nonatomic, copy) NSString *from;
/* 目标语言 */
@property (nonatomic, copy) NSString *to;
/* 采样率 */
@property (nonatomic, copy) NSString *rate;
/* 声道数，仅支持单声道，请填写固定值1 */
@property (nonatomic, copy) NSString *channel;
/* 翻译结果发音 */
@property (nonatomic, copy) NSString *voice;
+ (instancetype)param;
@end
