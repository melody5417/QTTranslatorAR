//
//  JSONDecoder.h
//  tar
//
//  Created by carmzhu on 2017/12/25.
//  Copyright © 2017年 carmzhu. All rights reserved.
//

#ifndef JSONDecoder_h
#define JSONDecoder_h

#import <Foundation/Foundation.h>

@interface JSONDecoder: NSObject
-(NSString*)description;
-(NSString*)stringValue;
-(int)integerValue;
-(uint)unsignedValue;
-(double)doubleValue;
-(float)floatValue;
-(BOOL)boolValue;
-(NSError*)errorValue;
-(NSDictionary<NSString*,JSONDecoder*>*)dictionaryValue;
-(NSArray*)arrayValue;
-(void)getArray:(NSMutableArray*)collection;
-(void)getDictionary:(NSMutableDictionary*)dict;
-(instancetype)init:(NSObject*)raw;
-(JSONDecoder*)subscriptInt:(int)index;
-(JSONDecoder*)subscriptString:(NSString*)key;
@end

@protocol JSONJoy<NSObject>
-(instancetype)init:(JSONDecoder*)decoder;
@end

#endif /* JSONDecoder_h */
