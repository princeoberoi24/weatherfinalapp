//
//  WeatherHTTPClient.h
//  Weather
//
//  Created by mac on 05/11/19.
//  Copyright © 2019 Scott Sherwood. All rights reserved.
//

@import AFNetworking;

@protocol WeatherHTTPClientDelegate;

@interface WeatherHTTPClient : AFHTTPSessionManager
@property (nonatomic, weak) id<WeatherHTTPClientDelegate>delegate;

+ (WeatherHTTPClient *)sharedWeatherHTTPClient;
- (instancetype)initWithBaseURL:(NSURL *)url;
- (void)updateWeatherAtLocation:(CLLocation *)location forNumberOfDays:(NSUInteger)number;

@end

@protocol WeatherHTTPClientDelegate <NSObject>
@optional
-(void)weatherHTTPClient:(WeatherHTTPClient *)client didUpdateWithWeather:(id)weather;
-(void)weatherHTTPClient:(WeatherHTTPClient *)client didFailWithError:(NSError *)error;
@end
