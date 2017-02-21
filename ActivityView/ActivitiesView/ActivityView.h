//
//  ActivityView.h
//  ActivityView
//
//  Created by chen cx on 2017/2/20.
//  Copyright © 2017年 chen cx. All rights reserved.
//

#import <UIKit/UIKit.h>

@class ButtonView;
@class ActivityView;

typedef void(^ButtonClickHandler) (ButtonView *buttonView);

@interface ButtonView : UIView

@property (nonatomic, strong) UILabel * textLabel;
@property (nonatomic, strong) UIButton * imageButton;

@property (nonatomic, weak) ActivityView * activityView;

- (id)initWithText:(NSString *)text image:(UIImage*)image handler:(ButtonClickHandler)handler;

@end

@interface ActivityView : UIView
// 背景颜色
@property (nonatomic, strong) UIColor *bgColor;
// 取消按钮
@property (nonatomic, strong) UIButton * cancelButton;

// 一行有多少个,默认是4 竖频不会多于4，横屏不会多于6 不建议ipad用这个
@property (nonatomic, assign) int numberOfButtonPerLine;

// 是否可以通过下滑手势关闭视图, 默认为YES
@property (nonatomic, assign) BOOL useGesture;

// 是否正在显示
@property (nonatomic, getter=isShowing) BOOL show;

- (id)initWithTitle:(NSString *)title referView:(UIView *)referView;

- (void)addButtonView:(ButtonView *)buttonView;

- (void)show;
- (void)hide;

@end
