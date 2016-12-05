//
//  HMemoCollectionViewCell.m
//  HMemo
//
//  Created by 余胜民 on 05/12/2016.
//  Copyright © 2016 susuyan. All rights reserved.
//

#import "HMemoCollectionViewCell.h"

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
    
    _contentLabel.numberOfLines = 11;
    _contentLabel.textAlignment = NSTextAlignmentLeft;

    [_contentLabel sizeToFit];
}

- (void)setupCell:(NSString *)content {
    self.contentLabel.text = content;
}
@end
