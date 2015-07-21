//
//  CEZoomImageView.h
//  BIPT_OA
//
//  Created by Thinkfer on 14-3-11.
//  Copyright (c) 2014年 Thinkfer. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CTDownloadImageView.h"

extern float DefaultZoomStep;//放大倍数
extern int DefaultZoomCount;//放大次数


@protocol CEZoomImageViewDelegate;

@interface CEZoomImageView : UIScrollView<UIScrollViewDelegate>
{
    CGPoint  _pointToCenterAfterResize;
    CGFloat  _scaleToRestoreAfterResize;
    float _zoomStep;//放大倍数
    int _zoomCount;//放大次数
}
@property(nonatomic,readwrite) float _zoomStep;//放大倍数
@property(nonatomic,readwrite) int _zoomCount;//放大次数
@property (retain, nonatomic) CTDownloadImageView *_imageView;
@property (assign, nonatomic) id<CEZoomImageViewDelegate> _imageViewDelegate;

//
- (void)prepareToResize;
- (void)recoverFromResizing;
@end

@protocol CEZoomImageViewDelegate <NSObject>
- (void)imageViewDidSingleTap:(CEZoomImageView *)imageView;
- (void)imageViewDidDoubleTap:(CEZoomImageView *)imageView;


@end