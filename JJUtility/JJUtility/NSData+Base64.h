//  NSString+JJUtility.h
//  JJUtility
//
//  Created by chenjie on 2017/07/18.
//  Copyright © 2017年 RobberJJ. All rights reserved.
//

#import <Foundation/Foundation.h>
@interface NSData (Base64)

/**
 base 64 encode from string

 @param string string encode to data
 @return data encdoed
 */
+ (NSData *)dataWithBase64EncodedString:(NSString *)string;

/**
 base 64 encode from data(self) to string

 @param wrapWidth wrap width
 @return string encoded
 */
- (NSString *)base64EncodedStringWithWrapWidth:(NSUInteger)wrapWidth;

/**
 base 64 encode from data(self) to string

 @return string encoded
 */
- (NSString *)base64EncodedString;

@end
