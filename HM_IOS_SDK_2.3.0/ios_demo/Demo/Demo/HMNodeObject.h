//
//  HMNodeObject.h
//  Demo
//
//  Created by guofeixu on 15/10/10.
//  Copyright © 2015年 guofeixu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HMNodeObject : NSObject

@property (assign, nonatomic) node_handle nodeHandle;
@property (assign, nonatomic) NODE_TYPE_INFO nodeType;
@property (strong, nonatomic) NSString *nodeName;
@property (assign, nonatomic) BOOL nodeIsOnline;

@end
