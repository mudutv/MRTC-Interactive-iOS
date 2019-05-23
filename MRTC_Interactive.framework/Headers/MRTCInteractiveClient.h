//
//  MRTCInteractiveClient.h
//  MRTC-Interactive
//
//  Created by 张志超 on 2019/2/13.
//  Copyright © 2019 mudu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,MRTCInteractiveClientState){
    kMRTCInterativeClienClosed,
    kMRTCInterativeClientConnecting,
    kMRTCInterativeClientConnected,
    kMRTCInterativeClientFailed
};

@class MRTCInteractiveClient;
@class MRTCError;
@class MRTCSetting;

@protocol MRTCInteractiveClientRoomDelegate <NSObject>

- (void)MRTCInteractiveClient:(MRTCInteractiveClient *)client joinSuccess:(NSArray<NSString *> *)roleArray;

- (void)MRTCInteractiveClient:(MRTCInteractiveClient *)client joinFailed:(MRTCError *)error;

- (void)MRTCInteractiveClient:(MRTCInteractiveClient *)client onJoinRoles:(NSArray<NSString *> *)roleArray;

- (void)MRTCInteractiveClient:(MRTCInteractiveClient *)client onLeaveRoles:(NSArray<NSString *> *)roleArray;

- (void)MRTCInteractiveClient:(MRTCInteractiveClient *)client playRoleSuccess:(NSString *)role;

- (void)MRTCInteractiveClient:(MRTCInteractiveClient *)client playRole:(NSString *)role failure:(MRTCError *)error;

@optional

- (void)MRTCInteractiveClient:(MRTCInteractiveClient *)client stateChanged:(MRTCInteractiveClientState)state;

- (void)MRTCInteractiveClient:(MRTCInteractiveClient *)client onError:(MRTCError *)error;

@end

@interface MRTCInteractiveClient : NSObject

@property (nonatomic, assign ,readonly) MRTCInteractiveClientState state;

@property (nonatomic, weak) id<MRTCInteractiveClientRoomDelegate> delegate;

- (instancetype)initWithHost:(NSString *)host setting:(MRTCSetting *)setting renderer:(UIView *)renderer;

- (void)joinWithChannel:(NSString *)channel role:(NSString *)role password:(NSString *)password delegate:(id<MRTCInteractiveClientRoomDelegate>)delegate;

- (void)leave;

- (void)playClientWithRole:(NSString *)role renderView:(UIView *)view;

- (void)stopClientWithRole:(NSString *)role;

- (void)enableLocalVideo:(BOOL)enable;

- (void)enableLocalAudio:(BOOL)enable;

- (void)enableRemoteAudio:(BOOL)enable;

- (void)switchCamera;

- (void)getHostStats:(void(^)(NSDictionary *stats))completion;

@end

NS_ASSUME_NONNULL_END
