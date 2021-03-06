//
//  KSYNVGPUStreamerKit.h
//  KSYStreamer
//
//  Created by ksyun.
//  Copyright © 2017 ksyun. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <libksygpulive/KSYGPUStreamerKit.h>

@interface KSYKiwiGPUStreamerKit : KSYGPUStreamerKit

/**
 @abstract 初始化方法
 @discussion 创建带有默认参数的 kit，不会打断其他后台的音乐播放
 
 @warning kit只支持单实例推流，构造多个实例会出现异常
 */
- (instancetype) initWithDefaultCfg;

/**
 @abstract   查询实际的采集分辨率
 @discussion 参见iOS的 AVCaptureSessionPresetXXX的定义
 */
@property (nonatomic, assign)   CGSize captureDimension;

/**
 @abstract   预览分辨率 (仅在开始采集前设置有效)
 @discussion 内部始终将较大的值作为宽度 (若需要竖屏，请设置 videoOrientation）
 @discussion 宽高都会向上取整为4的整数倍
 @discussion 有效范围: 宽度[160, 1920] 高度[ 90,  1080], 超出范围会取边界有效值
 @discussion 当预览分辨率与采集分辨率不一致时:
 若宽高比不同, 先进行裁剪, 再进行缩放
 若宽高比相同, 直接进行缩放
 @discussion 默认值为(640, 360)
 */
@property (nonatomic, assign)   CGSize previewDimension;

/**
 @abstract   用户定义的视频 **推流** 分辨率
 @discussion 有效范围: 宽度[160, 1280] 高度[ 90,  720], 超出范围会取边界有效值
 @discussion 其他与previewDimension限定一致,
 @discussion 当与previewDimension不一致时, 同样先裁剪到相同宽高比, 再进行缩放
 @discussion 默认值为(640, 360)
 @see previewDimension
 */
@property (nonatomic, assign)   CGSize streamDimension;

/**
 @abstract   摄像头朝向, 只在启动采集前设置有效
 @discussion 参见UIInterfaceOrientation
 @discussion 竖屏时: width < height
 @discussion 横屏时: width > height
 @discussion 需要与UI方向一致
 */
@property (nonatomic, assign) UIInterfaceOrientation videoOrientation;

/**
 @abstract  更新预览分辨率
 */
- (void) updatePreDimension;

/**
 @abstract 根据UI的朝向旋转推流画面, 这个是可以选的,可以不跟随旋转
 @param    orie 旋转到目标朝向, 需要从demo中获取UI的朝向传入
 @discussion 此函数与 streamOrientation 的set函数功能一样
 */
- (void) rotateStreamTo: (UIInterfaceOrientation) orie;

@end
