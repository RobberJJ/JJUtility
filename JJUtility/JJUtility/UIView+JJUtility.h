//
//  UIView+JJUtility.h
//  JJUtility
//
//  Created by chenjie on 2017/07/18.
//  Copyright © 2017年 RobberJJ. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (JJUtility)

//注意：Category中的属性，实际上只有setter和getter，而并没有生成成员变量

/**
 view的left与其superView left的距离，即frame.origin.x
 */
@property (nonatomic) CGFloat left;

/**
 view的top与其superView top的距离，即frame.origin.y
 */
@property (nonatomic) CGFloat top;

/**
 view的right与其superView left的距离，即frame.origin.x + frame.size.width
 */
@property (nonatomic) CGFloat right;

/**
 view的bottom与其superView top的距离，即frame.origin.y + frame.size.height
 */
@property (nonatomic) CGFloat bottom;

/**
 view的width，即frame.size.width
 */
@property (nonatomic) CGFloat width;

/**
 view的height，即frame.size.height
 */
@property (nonatomic) CGFloat height;

/**
 view左上顶点相对于其superView左上顶点的坐标，即frame.origin
 */
@property (nonatomic) CGPoint origin;

/**
 view的size，即frame.size
 */
@property (nonatomic) CGSize size;

/**
 view的中心点的横坐标，即(view.left + view.right) / 2.0f
 */
@property (nonatomic) CGFloat centerX;

/**
 view的中心点的纵坐标，即(view.top + view.bottom) / 2.0f
 */
@property (nonatomic) CGFloat centerY;

/**
 view的left距离屏幕left的直线距离
 */
@property (nonatomic, readonly) CGFloat linearScreenLeft;

/**
 view的top距离屏幕top的直线距离
 */
@property (nonatomic, readonly) CGFloat linearScreenTop;

/**
 view的right距离屏幕right的直线距离
 */
@property (nonatomic, readonly) CGFloat linearScreenRight;

/**
 view的bottom距离屏幕bottom的直线距离
 */
@property (nonatomic, readonly) CGFloat linearScreenBottom;

/**
 view相对于屏幕的直线frame
 */
@property (nonatomic, readonly) CGRect linearScreenFrame;

/**
 view的left距离屏幕left的实际距离(scrollView的contentOffset会计算在内)
 */
@property (nonatomic, readonly) CGFloat actualScreenLeft;

/**
 view的top距离屏幕top的实际距离(scrollView的contentOffset会计算在内)
 */
@property (nonatomic, readonly) CGFloat actualScreenTop;

/**
 view的right距离屏幕right的实际距离(scrollView的contentOffset会计算在内)
 */
@property (nonatomic, readonly) CGFloat actualScreenRight;

/**
 view的bottom距离屏幕bottom的实际距离(scrollView的contentOffset会计算在内)
 */
@property (nonatomic, readonly) CGFloat actualScreenBottom;

/**
 view相对于屏幕的实际frame(scrollView的contentOffset会计算在内)
 */
@property (nonatomic, readonly) CGRect actualScreenFrame;

/**
 移除所有subviews
 */
- (void)removeAllSubviews;

/**
 添加点击事件

 @param target 回调对象
 @param action 回调方法
 */
- (void)addTarget:(nullable id)target action:(SEL _Nullable )action;

/**
 移除点击事件
 */
- (void)removeTarget;

@end
