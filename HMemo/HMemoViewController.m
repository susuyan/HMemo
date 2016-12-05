//
//  HMemoViewController.m
//  HMemo
//
//  Created by 余胜民 on 05/12/2016.
//  Copyright © 2016 susuyan. All rights reserved.
//

#import "HMemoViewController.h"
#import "HMemoFlowLayout.h"
#import "HMemoCollectionViewCell.h"
#import "UIColor+RGBValues.h"

static NSString * const kAddItemIdentifier = @"kAddItemIdentifier";
static NSString * const kItemIdentifier = @"kItemIdentifier";

@interface HMemoViewController ()<UICollectionViewDelegate,UICollectionViewDataSource,HMemoFlowLayoutDelegate>
@property (weak, nonatomic) IBOutlet UICollectionView *collectionView;

@property (nonatomic, strong) NSArray *memoArray;

@end

@implementation HMemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    
    _memoArray = @[@"习了一段时间",
                   @"· 习了一段时间了",
                   @"习了一段时间了，对于这个文本内容多了需要计算高度的问题特别蛋疼，这个根本没法和Android相比啊，Android根本就不用自己费心计算宽度和高度，内部都帮你实现好了，好了，YY到此结束，遇到这么蛋疼的问题还得需要解决",
                   @"习了一段时间了，对于这个文本内容多了需要计算高度的问题特别蛋疼，这个根本没法和Android相比啊，Android根本就不用自己费心计算宽度和高度，内部都帮你实现好了，好了，YY到此结束，遇到这么蛋疼的问题还得需要解决",
                   @"习了一段时间了，对于这个文本内容多了需要计算高度的问题特别蛋疼，这个根本没法和Android相比啊，Android根本就不用自己费心计算宽度和高度，内部都帮你实现好了，好了，YY到此结束，遇到这么蛋疼的问题还得需要解决",
                   @"习了一段时间了，对于这个文本内容多了需要计算高度的问题特别蛋疼，这个根本没法和Android相比啊，Android根本就不用自己费YY到此结束，遇到这么蛋疼的问题还得需要解决",
                   @"习了一段时间了，对于这个文本内容多了需要计算高度的问题特别蛋疼，这个根本没法和Android相比啊，Android根本就不用自己费心计算宽度和高度你实现好到这么蛋疼的问题还得需要解决",
                   @"习了一段时间了，对于这个文本内容多了需要计算高度的问题特别蛋疼，这个根本没法和Android相比啊，Android根本就不用自己费心计算宽度和高度，内部都帮你实现好了，好了，YY到此结束，遇到这么蛋疼的问题还得需要解决",
                   @"习了一段时间了，对要计算高度的问题特别蛋疼，这个根本没法和Android相比啊，Android根本就不用自己费心计算宽度和高度，内部都帮你实现好了，好了，YY到此结束，遇到这么蛋疼的问题还得需要解决",
                   @"习了一段时间蛋疼，这个根本没法和Android相比啊，Android根本就不用自己费心计算宽度和高度，内部都帮你实现好了，好了，YY到此结束，遇到这么蛋疼的问题还得需要解决",];
    
    HMemoFlowLayout *layout = [[HMemoFlowLayout alloc] init];
    layout.delegate = self;
    
    self.collectionView.collectionViewLayout = layout;
    
    [self.collectionView registerNib:[UINib nibWithNibName:@"HMemoCollectionViewCell" bundle:nil] forCellWithReuseIdentifier:kItemIdentifier];
}

#pragma mark - UICollection Datasource
- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
    
    
    return 10;
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
    
    if (indexPath.item == 0) {
        UICollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:kAddItemIdentifier forIndexPath:indexPath];
        
        cell.backgroundColor = [UIColor colorFromHexRGB:@"f8f8f8"];
        
        
        return cell;
        
    }else {
        
        HMemoCollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:kItemIdentifier forIndexPath:indexPath];

        if (!cell) {
            cell = [[HMemoCollectionViewCell alloc] init];
        }
        [cell setupCell:_memoArray[indexPath.item-1]];
        
        return cell;

        
    }
    
}


#pragma mark - HMemoFlowLayoutDelegate
- (CGFloat)collectionView:(UICollectionView *)collectionView layout:(HMemoFlowLayout *)collectionViewLayout heightForItemAtIndexPath:(NSIndexPath *)indexPath {
    
    CGFloat itemWidth = ([UIScreen mainScreen].bounds.size.width - 32)/2 ;
    
    if (indexPath.item == 0) {
        return itemWidth;
    }
    
    NSString *contentString = _memoArray[indexPath.item-1];
    
    
    CGFloat itemHeight = [contentString boundingRectWithSize:CGSizeMake(itemWidth, MAXFLOAT)
                                                     options:NSStringDrawingUsesLineFragmentOrigin
                                                  attributes:@{NSFontAttributeName:[UIFont systemFontOfSize:15],
                                                               } context:nil].size.height;
    long charSize = lroundf([UIFont systemFontOfSize:16].lineHeight);
    CGFloat lineCount = (int)( itemHeight / charSize );
    if (lineCount >= 11) {
        itemHeight += 30 +10;
    }else{
        itemHeight += charSize + 30 +10;
    }

    
    return itemHeight;
}
@end
