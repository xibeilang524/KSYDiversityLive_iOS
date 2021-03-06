//
//  TuSDKVideoSourceProtocol.h
//  TuSDKVideo
//
//  Created by Yanlin on 4/20/16.
//  Copyright © 2016 TuSDK. All rights reserved.
//

#import "TuSDKVideoCameraBase.h"

/**
 *  视频输出协议
 */
@protocol TuSDKVideoSourceProtocol <NSObject>

/**
 *  系统相机对象
 */
@property (readonly) AVCaptureDevice *inputCamera;

/**
 *  摄像头位置
 */
- (AVCaptureDevicePosition)cameraPosition;

/**
 *  旋转模式
 *
 *  @return
 */
- (GPUImageRotationMode)getInternalRotation;

/**
 *  设备当前朝向
 *
 *  @return
 */
- (UIDeviceOrientation)getDeviceOrientation;

/**
 *  获取聚焦视图
 *
 *  @return
 */
- (UIView<TuSDKVideoCameraExtendViewInterface> *)getFocusTouchView;

/**
 *  更新脸部信息
 *
 *  @param points      特征点数据
 *  @param deviceAngle 设备角度
 */
- (void)updateFaceFeatures:(NSArray<NSValue *> *)points angle:(CGFloat)deviceAngle;

@end

#pragma mark - TuSDKVideoOutputWriter

/**
 *  视频输出接口
 */
@protocol TuSDKVideoOutputWriter <GPUImageInput>

/**
 *  相机对象
 */
@property (nonatomic, assign) id<TuSDKVideoCameraInterface> camera;

/**
 *  相机位置发生改变
 */
- (void)onCameraPositionChanged;

/**
 *  开始视频录制
 */
- (void)startRecording;

/**
 *  完成视频录制
 */
- (void)finishRecording;

/**
 *  终止录制
 */
- (void)cancelRecording;

/**
 *  完成视频录制，且在完成后，执行block内容
 */
- (void)publicFinishRecordingWithCompletionHandler:(void (^)(void))handler;

@end
