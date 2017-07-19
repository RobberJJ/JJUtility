//
//  NSString+JJUtility.h
//  JJUtility
//
//  Created by chenjie on 2017/07/18.
//  Copyright © 2017年 RobberJJ. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonDigest.h>
//#import <CommonCrypto/CommonCryptor.h>

@interface NSString (JJUtility)

/**
 string md5

 @return 返回md5之后的string
 */
- (NSString *)md5;

/**
 get sha1

 @return 返回sha1
 */
- (NSString *)SHA1;

/**
 编码
 
 @return 返回编码后的字符串
 */
- (NSString *)encode;

/**
 编码，自定义字符集

 @param allowedCharacters 字符集 如 @"`#%^{}\"[]|\\<> "
 @return 返回编码之后的字符串
 */
- (NSString *)encodeWithAllowedCharactersString:(NSString *)allowedCharacters;

/**
 解码

 @return 返回解码后的字符串
 */
- (NSString *)decode;

@end
