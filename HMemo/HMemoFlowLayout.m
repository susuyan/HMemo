//
//  HMemoFlowLayout.m
//  HMemo
//
//  Created by 余胜民 on 03/12/2016.
//  Copyright © 2016 susuyan. All rights reserved.
//

#import "HMemoFlowLayout.h"

static const NSInteger kLineSpacing = 8;
static const NSInteger kInteritemSpacing = 9;

static const UIEdgeInsets kCollectionViewEdgeInsets = {5, 12, 5, 12};

static const int kColumsCount = 2;
@interface HMemoFlowLayout ()

@property (nonatomic, strong) NSMutableArray *columMaxHeightArray;

@property (nonatomic, strong) NSMutableArray *attrsArray;

@end

@implementation HMemoFlowLayout

- (void)prepareLayout {
    [super prepareLayout];
    
    self.minimumLineSpacing = kLineSpacing;
    self.minimumInteritemSpacing = kInteritemSpacing;
    
    
    self.scrollDirection = UICollectionViewScrollDirectionVertical;
    
    
    // 重置每一列的最大Y值
    [self.columMaxHeightArray removeAllObjects];
    for (NSUInteger i = 0; i<2; i++) {
        [self.columMaxHeightArray addObject:@(kCollectionViewEdgeInsets.top)];
    }
    
    // 计算所有cell的布局属性
    [self.attrsArray removeAllObjects];
    NSUInteger count = [self.collectionView numberOfItemsInSection:0];
    for (NSUInteger i = 0; i < count; ++i) {
        NSIndexPath *indexPath = [NSIndexPath indexPathForItem:i inSection:0];
        UICollectionViewLayoutAttributes *attrs = [self layoutAttributesForItemAtIndexPath:indexPath];
        [self.attrsArray addObject:attrs];
    }
    
   
}



- (NSMutableArray *)columMaxHeightArray {
    if (!_columMaxHeightArray) {
        _columMaxHeightArray = [[NSMutableArray alloc] init];
    }
    
    return _columMaxHeightArray;
}

- (NSMutableArray *)attrsArray {
    if (!_attrsArray) {
        _attrsArray = [NSMutableArray array];
    }
    return _attrsArray;
}

- (CGSize)collectionViewContentSize {
    

    CGFloat destMaxY = [self.columMaxHeightArray[0] doubleValue];
    for (NSUInteger i = 1; i<self.columMaxHeightArray.count; i++) {
        // 取出第i列的最大Y值
        CGFloat columnMaxY = [self.columMaxHeightArray[i] doubleValue];
        
        // 找出数组中的最大值
        if (destMaxY < columnMaxY) {
            destMaxY = columnMaxY;
        }
    }
    return CGSizeMake(0, destMaxY + kCollectionViewEdgeInsets.bottom);
}
- (NSArray *)layoutAttributesForElementsInRect:(CGRect)rect {
    
    return self.attrsArray;
}

- (UICollectionViewLayoutAttributes *)layoutAttributesForItemAtIndexPath:(NSIndexPath *)indexPath {
    
    UICollectionViewLayoutAttributes *attrs = [UICollectionViewLayoutAttributes layoutAttributesForCellWithIndexPath:indexPath];
    
    /** 计算indexPath位置cell的布局属性 */
    
    // 水平方向上的总间距
    CGFloat xMargin = kCollectionViewEdgeInsets.left + kCollectionViewEdgeInsets.right + (kColumsCount - 1) * 10;
    // cell的宽度
    CGFloat width = ([UIScreen mainScreen].bounds.size.width - xMargin) / kColumsCount;
    // cell的高度，测试数据，随机数
//    CGFloat height = 80 + arc4random_uniform(300);
    CGFloat height;
    
    if (_delegate) {
        height = [self.delegate collectionView:self.collectionView layout:self heightForItemAtIndexPath:indexPath];
    }else {
        height = width;
    }
    
    
    
       
    // 找出最短那一列的 列号 和 最大Y值
    CGFloat destMaxY = [self.columMaxHeightArray[0] doubleValue];
    NSUInteger currentColumn = 0;
    for (NSUInteger i = 1; i<self.columMaxHeightArray.count; i++) {
        // 取出第i列的最大Y值
        CGFloat columnMaxY = [self.columMaxHeightArray[i] doubleValue];
        
        // 找出数组中的最小值
        if (destMaxY > columnMaxY) {
            destMaxY = columnMaxY;
            currentColumn = i;
        }
    }
    
    // cell的x值
    CGFloat x = kCollectionViewEdgeInsets.left + currentColumn * (width + 10);
    // cell的y值
    CGFloat y = destMaxY + 10;
    // cell的frame
    attrs.frame = CGRectMake(x, y, width, height);
    
    // 更新数组中的最大Y值
    self.columMaxHeightArray[currentColumn] = @(CGRectGetMaxY(attrs.frame));
    
    

    return attrs;
}
@end
