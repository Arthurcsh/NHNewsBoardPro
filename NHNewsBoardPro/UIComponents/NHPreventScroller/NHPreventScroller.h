//
//  NHPreventScroller.h
//  NHNewsBoardPro
//
//  Created by hu jiaju on 16/4/8.
//  Copyright © 2016年 hu jiaju. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 *  @brief 尝试实现网易布局
 *  
 *  @attention: 本组件在同一时刻最多显示(预加载)6个页面(网易策略)
 *
 */
@class NHNews;
@protocol NHPreventScrollerDelegate;
@interface NHPreventScroller : UIScrollView

@property (nonatomic, assign) _Nullable id<NHPreventScrollerDelegate> preventDelegate;

/**
 *  @brief 初始化 方法
 *
 *  @param frame bounds for display
 *  @param cnns  所有已订阅频道集合
 *
 *  @return 实例
 */
- (id _Nonnull)initWithFrame:(CGRect)frame withCnns:(NSArray * _Nonnull)cnns;

#pragma mark -- 频道编辑完毕 可调取方法刷新当前页面
/**
 *  @brief 强制刷新
 */
- (void)viewDidAppear;

/**
 *  @brief 内存紧张时处理
 *
 *  @attention:当内存紧张时页面均置为lowPower state（除了当前显示页面）
 */
- (void)didReceivedMemoryWarning;

#pragma mark -- 栏目编辑事件
/**
 *  @brief 切换栏目
 *
 *  @param idx 序号
 */
- (void)preventScrollChange2Cnn:(NSString * _Nonnull)cnn;

/**
 *  @brief 增、删栏目
 *
 *  @param add 是否是增加 否为删除
 *  @param idx 序号
 *  @param cnn 栏目名称
 */
- (void)preventScrollEdit:(BOOL)add idx:(NSUInteger)idx cnn:(NSString * _Nonnull)cnn;

/**
 *  @brief 排序栏目
 *
 *  @param originIdx 原始序号
 *  @param destIdx   目标序号
 *  @param cnn       栏目名称
 */
- (void)preventScrollSort:(NSUInteger)originIdx destIdx:(NSUInteger)destIdx cnn:(NSString * _Nonnull)cnn;

@end

@protocol NHPreventScrollerDelegate <NSObject>
@optional
- (void)preventScroller:(NHPreventScroller * _Nonnull)scroller didShowCnn:(NSString * _Nonnull)cnn;
- (void)preventScroller:(NHPreventScroller * _Nonnull)scroller didSelectNews:(NHNews * _Nonnull)info;
- (void)preventScroller:(NHPreventScroller * _Nonnull)scroller didSelectADs:(NSDictionary * _Nonnull)ad;
@end
