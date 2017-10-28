//
//  NSString+JJUtility.m
//  JJUtility
//
//  Created by chenjie on 2017/07/18.
//  Copyright © 2017年 RobberJJ. All rights reserved.
//

#import "NSString+JJUtility.h"
#import "NSData+Base64.h"

@implementation NSString (JJUtility)

-(NSString *)md5 {
    // 分配MD5结果空间
    uint8_t *md5Bytes = malloc(CC_MD5_DIGEST_LENGTH * sizeof(uint8_t));
    if(md5Bytes)
    {
        memset(md5Bytes, 0x0, CC_MD5_DIGEST_LENGTH);
        
        // 计算hash值
        NSData *srcData = [self dataUsingEncoding:NSUTF8StringEncoding];
        CC_MD5((void *)[srcData bytes], (CC_LONG)[srcData length], md5Bytes);
        
        // 组建String
        NSMutableString* destString = [NSMutableString stringWithCapacity:CC_MD5_DIGEST_LENGTH * 2];
        for(int i = 0; i < CC_MD5_DIGEST_LENGTH; i++)
        {
            [destString appendFormat:@"%02X", md5Bytes[i]];
        }
        
        // 释放空间
        free(md5Bytes);
        
        return destString;
    }
    
    return nil;
}

- (NSString *)SHA1
{
    // 分配hash结果空间
    uint8_t *hashBytes = malloc(CC_SHA1_DIGEST_LENGTH * sizeof(uint8_t));
    if(hashBytes)
    {
        memset(hashBytes, 0x0, CC_SHA1_DIGEST_LENGTH);
        
        // 计算hash值
        NSData *srcData = [self dataUsingEncoding:NSUTF8StringEncoding];
        CC_SHA1((void *)[srcData bytes], (CC_LONG)[srcData length], hashBytes);
        
        // 组建String
        NSMutableString* destString = [NSMutableString stringWithCapacity:CC_SHA1_DIGEST_LENGTH * 2];
        for(int i = 0; i < CC_SHA1_DIGEST_LENGTH; i++)
        {
            [destString appendFormat:@"%02X", hashBytes[i]];
        }
        
        // 释放空间
        free(hashBytes);
        
        return destString;
    }
    
    return nil;
}


- (NSString *)encode
{
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_9_0
    return [self stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet characterSetWithCharactersInString:@"`#%^{}\"[]|\\<> "]];
#else
    NSString *result = (__bridge_transfer NSString *)
    CFURLCreateStringByAddingPercentEscapes(kCFAllocatorDefault,
                                            (CFStringRef)self,
                                            NULL,
                                            CFSTR("`#%^{}\"[]|\\<> "),
                                            kCFStringEncodingUTF8);
    return result;
#endif
}

- (NSString *)encodeWithAllowedCharactersString:(NSString *)allowedCharacters {
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_9_0
    return [self stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet characterSetWithCharactersInString:allowedCharacters]];
#else
    NSString *result = (__bridge_transfer NSString *)
    CFURLCreateStringByAddingPercentEscapes(kCFAllocatorDefault,
                                            (CFStringRef)self,
                                            NULL,
                                            (__bridge CFStringRef)allowedCharacters,
                                            kCFStringEncodingUTF8);
    return result;
#endif
}

- (NSString*)decode
{
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_9_0
    return [self stringByRemovingPercentEncoding];
#else
    NSString *result = (__bridge_transfer NSString *)
    CFURLCreateStringByReplacingPercentEscapesUsingEncoding(kCFAllocatorDefault,
                                                            (CFStringRef)self,
                                                            CFSTR(""),
                                                            kCFStringEncodingUTF8);
    return result;
#endif
}

@end

@implementation NSString (Base64)
+ (NSString *)stringWithBase64EncodedString:(NSString *)string
{
    NSData *data = [NSData dataWithBase64EncodedString:string];
    if (data)
    {
        NSString *result = [[self alloc]
                            initWithData:data encoding:NSUTF8StringEncoding];
        
#if !__has_feature(objc_arc)
        [result autorelease];
#endif
        return result;
    }
    return nil;
}
- (NSString *)base64EncodedStringWithWrapWidth:(NSUInteger)wrapWidth
{
    NSData *data = [self dataUsingEncoding:NSUTF8StringEncoding allowLossyConversion:YES];
    return [data base64EncodedStringWithWrapWidth:wrapWidth];
}
- (NSString *)base64EncodedString
{
    NSData *data = [self dataUsingEncoding:NSUTF8StringEncoding allowLossyConversion:YES];
    return [data base64EncodedString];
}
- (NSString *)base64DecodedString
{
    return [NSString stringWithBase64EncodedString:self];
}
- (NSData *)base64DecodedData
{
    return [NSData dataWithBase64EncodedString:self];
}
@end
