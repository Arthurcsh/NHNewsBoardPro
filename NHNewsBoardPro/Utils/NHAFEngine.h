//
//  NHAFEngine.h
//  NHCerSecurityPro
//
//  Created by hu jiaju on 15/7/30.
//  Copyright (c) 2015年 hu jiaju. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AFNetworking/AFNetworking.h>

@interface NHAFEngine : AFHTTPSessionManager

/**
 *	@brief	network engine singleton
 *
 *	@return	instance
 */
+ (NHAFEngine * _Nonnull)share;


/**
 *	@brief	cancel a request
 *
 *	@param 	path 	the request's path
 */
- (void)cancelRequestForpath:(NSString * _Nonnull)path;


- (void)POST:(NSString * _Nonnull)path parameters:(id _Nullable)parameters vcr:(UIViewController * _Nullable)vcr success:(void (^)(NSURLSessionDataTask *task, id responseObj))success failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;

- (void)POST:(NSString * _Nonnull)path parameters:(id _Nullable)parameters vcr:(UIViewController * _Nullable)vcr view:(UIView *_Nullable)view success:(void (^)(NSURLSessionDataTask *task, id responseObj))success failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;

@end
