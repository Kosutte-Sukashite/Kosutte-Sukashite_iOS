//
//  ImobileSdkAds.h
//
//  Copyright (c) 2013年 i-mobile. All rights reserved.
//

#pragma mark - ImobileSdkAds

@class ImobileSdkAdsIconParams;
@protocol IMobileSdkAdsDelegate;

#pragma mark 広告の表示レイアウト
typedef enum {
    IMOBILESDKADS_AD_ORIENTATION_AUTO,      // 自動判別
    IMOBILESDKADS_AD_ORIENTATION_PORTRAIT,  // ポートレート固定
    IMOBILESDKADS_AD_ORIENTATION_LANDSCAPE, // ランドスケープ固定
} ImobileSdkAdsAdOrientation;

#pragma mark - 広告表示準備完了時の広告の種類(アプリ側への通知内容)
typedef enum {
    IMOBILESDKADS_READY_AD,                 // 通常広告
    IMOBILESDKADS_READY_HOUSE_AD            // 自社広告
} ImobileSdkAdsReadyResult;

#pragma mark - アプリ側からの確認(getStatusBySpotID)用
typedef enum {
    IMOBILESDKADS_STATUS_READY,
    IMOBILESDKADS_STATUS_NOT_READY,
    IMOBILESDKADS_STATUS_NOT_FOUND,
    IMOBILESDKADS_STATUS_RETRY_WAIT,
    IMOBILESDKADS_STATUS_OTHERS
} ImobileSdkAdsStatus;

#pragma mark - 広告取得失敗時のエラーの種類(アプリ側への通知内容)
typedef enum {
    IMOBILESDKADS_ERROR_PARAM,              // パラメータエラー
    IMOBILESDKADS_ERROR_AUTHORITY,          // 権限エラー
    IMOBILESDKADS_ERROR_RESPONSE,           // レスポンスエラー
    IMOBILESDKADS_ERROR_NETWORK_NOT_READY,  // ネットワーク使用不可
    IMOBILESDKADS_ERROR_NETWORK,            // ネットワークエラー
    IMOBILESDKADS_ERROR_UNKNOWN,            // 不明なエラー
    IMOBILESDKADS_ERROR_AD_NOT_READY,       // 広告表示準備未完了
    IMOBILESDKADS_ERROR_NOT_FOUND,          // 広告切れ
    IMOBILESDKADS_ERROR_SHOW_TIMEOUT        // 広告表示処理タイムアウト
} ImobileSdkAdsFailResult;

#pragma mark - 広告表示準備完了時の広告の種類(アプリ側への通知内容)
typedef enum {
    IMOBILESDKADS_FILTER_MODE_UNKONWN,      // フィルターモードの情報が取得できていない
    IMOBILESDKADS_FILTER_MODE_YES,          // フィルターモード
    IMOBILESDKADS_FILTER_MODE_NO            // 非フィルターモード
} ImobileSdkAdsFilterMode;


#pragma mark -ImobileSdkAds(SDK本体)
@interface ImobileSdkAds : NSObject

// 広告を受け取る広告枠の情報を登録します
// 戻り値：広告枠が登録された場合はYES
+ (BOOL)registerWithPublisherID:(NSString *)publisherId MediaID:(NSString *)mediaId SpotID:(NSString *)spotId;

// 登録済みのすべての広告枠の広告取得を開始します
+ (void)start;

// 登録済みのすべての広告枠の広告取得を停止します
+ (void)stop;

// 登録済みの指定された広告枠の広告取得を開始します
// 戻り値：スポットが登録済みの場合、YES
+ (BOOL)startBySpotID:(NSString *)spotId;

// 登録済みの指定された広告枠の広告取得を停止します
// 戻り値：スポットが登録済みの場合、YES
+ (BOOL)stopBySpotID:(NSString *)spotId;

#pragma mark - 広告の表示
#pragma mark - 広告の表示(全画面)
// 登録済みの指定された広告枠が表示可能な場合、広告を表示します
// 戻り値：スポットが登録済みの場合、YES
+ (BOOL)showBySpotID:(NSString *)spotId;

#pragma mark - 広告の表示(インライン)
#pragma mark 広告の表示(座標(ViewController)指定)
// 登録済みの指定された広告枠が表示可能な場合、広告を表示します(ViewController指定版、表示位置指定版 for インライン)
// 戻り値：スポットが登録済みの場合、YES
+ (BOOL)showBySpotID:(NSString *)spotId ViewController:(UIViewController *)viewController Position:(CGPoint)position;

// 登録済みの指定された広告枠が表示可能な場合、広告を表示します(ViewController指定版、表示位置指定版 for インライン 広告表示を横幅に合わせるフラグ指定可(アイコン広告の場合は無効))
// 戻り値：スポットが登録済みの場合、YES
+ (BOOL)showBySpotID:(NSString *)spotId ViewController:(UIViewController *)viewController Position:(CGPoint)position SizeAdjust:(BOOL)sizeAdjust;

// 登録済みの指定された広告枠が表示可能な場合、アイコン表示パラメータに従って広告を表示します(ViewController指定版、表示位置指定版 for インライン)
// 戻り値：スポットが登録済みの場合、YES
+ (BOOL)showBySpotID:(NSString *)spotId ViewController:(UIViewController *)viewController Position:(CGPoint)position IconPrams:(ImobileSdkAdsIconParams *)iconParams;

#pragma mark 広告の表示(View指定)
// 登録済みの指定された広告枠が表示可能な場合、広告を表示します(View指定版 for インライン)
// 戻り値：スポットが登録済みの場合、YES
+ (BOOL)showBySpotID:(NSString *)spotId View:(UIView *)view;

// 登録済みの指定された広告枠が表示可能な場合、広告を表示します(View指定版 for インライン 広告表示を横幅に合わせるフラグ指定可(アイコン広告の場合は無効))
// 戻り値：スポットが登録済みの場合、YES
+ (BOOL)showBySpotID:(NSString *)spotId View:(UIView *)view SizeAdjust:(BOOL)sizeAdjust;

// 登録済みの指定された広告枠が表示可能な場合、アイコン表示パラメータに従って広告を表示します(View指定版 for インライン)
// 戻り値：スポットが登録済みの場合、YES
+ (BOOL)showBySpotID:(NSString *)spotId View:(UIView *)view IconPrams:(ImobileSdkAdsIconParams *)iconParams;

#pragma mark 広告の表示(インライン AdMobMediation)
// AdMobMediation用のShowAd
// 戻り値：スポットが登録済みの場合、YES
+ (BOOL)showBySpotIDForAdMobMediation:(NSString *)spotId View:(UIView *)view;

#pragma mark - setter
// SDKのメッセージを受け取るデリゲートを設定します
// 戻り値：スポットが登録済みの場合、YES
+ (BOOL)setSpotDelegate:(NSString *)spotId delegate:(id<IMobileSdkAdsDelegate>)delegate;

// テストモードの設定をします
// isTestModeが、YES：テスト広告を配信します, NO：通常広告を配信します
// 初期値：NO
+ (void)setTestMode:(BOOL)isTestMode;

// 広告が表示される向きの設定
// 初期値：AUTO
+ (void)setAdOrientation:(ImobileSdkAdsAdOrientation)orientation;

// ルートコントロールビューを設定します
+ (void)setRootViewController:(UIViewController *)rootViewController;

// Xcode5(iOS7 SDK)でのビルドに対応するかを設定
+ (void)setLegacyIosSdkMode:(BOOL)isLegacyMode;

// フィルターモードを取得します
+ (ImobileSdkAdsFilterMode)getFilterModeBySpotId:(NSString *)spotId;

// オフスクリーンウインドウのウインドウレベルを設定します
+ (void)setOffscreenWindowLevel:(UIWindowLevel)windowLevel __deprecated;

#pragma mark - getter
// 登録済みの指定された広告枠の状態を取得します
// スポットが登録されていない場合は、nilが返ります。
+ (ImobileSdkAdsStatus)getStatusBySpotID:(NSString *)spotId;

// skipCountに達するまで、Showメソッドが呼ばれた回数
// スポットが登録されていない場合は、nilが返ります。
+ (NSNumber *)getCountAttemptsToShowBySpotID:(NSString *)spotId;

// Showメソッドが呼ばれた回数の合計
// スポットが登録されていない場合は、nilが返ります。
+ (NSNumber *)getCountAttemptsToShowTotalBySpotID:(NSString *)spotId;

@end


#pragma mark - IMobileSdkAdsDelegate
// SDKのメッセージを受け取るデリゲート(アプリ単位)
@protocol IMobileSdkAdsDelegate <NSObject>

// 広告の表示が準備完了した際に呼ばれます
@optional
- (void)imobileSdkAdsSpot:(NSString *)spotId didReadyWithValue:(ImobileSdkAdsReadyResult)value;

// 広告の取得を失敗した際に呼ばれます
@optional
- (void)imobileSdkAdsSpot:(NSString *)spotId didFailWithValue:(ImobileSdkAdsFailResult)value;

// 広告の表示要求があった際に、準備が完了していない場合に呼ばれます
@optional
- (void)imobileSdkAdsSpotIsNotReady:(NSString *)spotId;

// 広告クリックした際に呼ばれます
@optional
- (void)imobileSdkAdsSpotDidClick:(NSString *)spotId;

// 広告を閉じた際に呼ばれます(広告の表示がスキップされた場合も呼ばれます)
@optional
- (void)imobileSdkAdsSpotDidClose:(NSString *)spotId;

// 広告の表示が完了した際に呼ばれます
@optional
- (void)imobileSdkAdsSpotDidShow:(NSString *)spotId;

// フィルターモードの情報が取得完了した際に呼ばれます
@optional
- (void)imobileSdkAdsSpotDidGetFilterMode:(NSString *)spotId;

@end

