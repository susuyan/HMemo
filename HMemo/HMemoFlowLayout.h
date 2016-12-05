//
//  HMemoFlowLayout.h
//  HMemo
//
//  Created by 余胜民 on 03/12/2016.
//  Copyright © 2016 susuyan. All rights reserved.
//

#import <UIKit/UIKit.h>

@class HMemoFlowLayout;

@protocol HMemoFlowLayoutDelegate <UICollectionViewDelegate>

- (CGFloat)collectionView:(UICollectionView *)collectionView
                   layout:(HMemoFlowLayout *)collectionViewLayout
 heightForItemAtIndexPath:(NSIndexPath *)indexPath;

@end


@interface HMemoFlowLayout : UICollectionViewFlowLayout

@property (nonatomic, assign) id <HMemoFlowLayoutDelegate>delegate;

@end
