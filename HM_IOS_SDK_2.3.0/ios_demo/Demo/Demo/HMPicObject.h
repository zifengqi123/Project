//
//  HMPicObject.h
//  Demo
//
//  Created by guofeixu on 15/11/5.
//  Copyright © 2015年 guofeixu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HMPicObject : NSObject

@property (strong, nonatomic) NSString *fileName;
@property (assign, nonatomic) NSInteger fileSize;
@property (assign, nonatomic) PIC_CAP_TYPE capType;
@property (strong, nonatomic) NSString *capTime;


@end