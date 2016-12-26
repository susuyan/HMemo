//
//  HMemoCollectionViewCell.m
//  HMemo
//
//  Created by 余胜民 on 05/12/2016.
//  Copyright © 2016 susuyan. All rights reserved.
//

#import "HMemoCollectionViewCell.h"
#import "UIColor+RGBValues.h"
#import "UILabel+Caculate.h"
@interface HMemoCollectionViewCell ()
@property (weak, nonatomic) IBOutlet UILabel *contentLabel;

@end

@implementation HMemoCollectionViewCell

- (id)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        [self commmonInit];
    }
    return self;
}

- (id)initWithCoder:(NSCoder *)aDecoder {
    self = [super initWithCoder:aDecoder];
    if (self) {
        [self commmonInit];
    }
    return self;
}

- (void)commmonInit {
    
    
//    _contentLabel.textAlignment = NSTextAlignmentLeft;
//    [_contentLabel sizeToFit];
    
    UIView* backgroundView = [[UIView alloc] initWithFrame:self.bounds];
    backgroundView.backgroundColor = [UIColor colorFromHexRGB:@"f8f8f8"];
    self.backgroundView = backgroundView;
    
    UIView* selectedBGView = [[UIView alloc] initWithFrame:self.bounds];
    selectedBGView.backgroundColor = [UIColor colorFromHexRGB:@"FEFA8D"];
    self.selectedBackgroundView = selectedBGView;
}

- (void)setupCell:(NSString *)content {
    
    self.contentLabel.text = content;

    if ([self.contentLabel numberOfText] >= 11) {
        
        self.contentLabel.numberOfLines = 11;


        
    }else {
        self.contentLabel.numberOfLines = 0;
        
        
    }
    

    
//    NSLog(@"item 行数为：%ld",(long)[self.contentLabel caculateLineCount]);
}
@end
