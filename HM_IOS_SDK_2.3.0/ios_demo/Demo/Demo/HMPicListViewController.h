//
//  HMPicListViewController.h
//  Demo
//
//  Created by guofeixu on 15/11/5.
//  Copyright © 2015年 guofeixu. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface HMPicListViewController : UIViewController

@property (assign, nonatomic) user_id userId;
@property (strong, nonatomic) HMNodeObject *nodeObject;
@property (strong, nonatomic) HMChannelObject *channelObject;

@end
