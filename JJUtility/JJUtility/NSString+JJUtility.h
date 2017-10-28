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

@interface NSString (Base64)
/**
 base64 encode

 @param string string need to encode
 @return string encoded
 */
+ (NSString *)stringWithBase64EncodedString:(NSString *)string;

/**
 base64 encode with wrap width

 @param wrapWidth wrap width
 @return strnig encoded
 */
- (NSString *)base64EncodedStringWithWrapWidth:(NSUInteger)wrapWidth;

/**
 base64 encdoe

 @return string ecoded
 */
- (NSString *)base64EncodedString;

/**
 base64 decode

 @return string decoded
 */
- (NSString *)base64DecodedString;

/**
 base64 decode from string(self) to data

 @return data decoded from string
 */
- (NSData *)base64DecodedData;
@end
