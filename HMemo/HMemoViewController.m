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
#import "HEditViewController.h"

static NSString * const kAddItemIdentifier = @"kAddItemIdentifier";
static NSString * const kItemIdentifier = @"kItemIdentifier";

@interface HMemoViewController ()<UICollectionViewDelegate,UICollectionViewDataSource,UICollectionViewDelegateFlowLayout,HMemoFlowLayoutDelegate>
@property (weak, nonatomic) IBOutlet UICollectionView *collectionView;

@property (nonatomic, strong) NSArray *memoArray;

@property (nonatomic) BOOL deleteEnabled;
@property (nonatomic, strong) NSMutableArray *selectedMemos;

@end

@implementation HMemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    
    _memoArray = @[@"习了一段时间习了一段时间了，",
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
    
    _selectedMemos = [NSMutableArray array];
    
    _deleteEnabled = NO;
}

#pragma mark - UICollectionView Datasource
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

#pragma mark - UICollectionView Delegate
- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath {
    
    if (_deleteEnabled) {
        NSString *selectedMemo = _memoArray[indexPath.item];
        [_selectedMemos addObject:selectedMemo];
    }else {
        
        HMemoCollectionViewCell *cell = (HMemoCollectionViewCell *)[collectionView cellForItemAtIndexPath:indexPath];
        if (cell.isSelected) {
            [collectionView selectItemAtIndexPath:indexPath animated:YES scrollPosition:UICollectionViewScrollPositionNone];
        }
        
        HEditViewController *editViewController = [[UIStoryboard storyboardWithName:@"Main" bundle:nil] instantiateViewControllerWithIdentifier:@"HEditViewController"];
        [self.navigationController pushViewController:editViewController animated:YES];
    }
    
    
    
}

- (void)collectionView:(UICollectionView *)collectionView didDeselectItemAtIndexPath:(NSIndexPath *)indexPath {
    if (_deleteEnabled) {
        NSString *selectedMemo = _memoArray[indexPath.item];
        [_selectedMemos removeObject:selectedMemo];
    }
}


#pragma mark - HMemoFlowLayoutDelegate
- (CGFloat)collectionView:(UICollectionView *)collectionView layout:(HMemoFlowLayout *)collectionViewLayout heightForItemAtIndexPath:(NSIndexPath *)indexPath {
    
    CGFloat itemWidth = ([UIScreen mainScreen].bounds.size.width - 32)/2 ;
    
    if (indexPath.item == 0) {
        return itemWidth;
    }
    
    NSString *contentString = _memoArray[indexPath.item-1];
    
    
    CGFloat itemHeight = ceilf([contentString boundingRectWithSize:CGSizeMake(itemWidth, MAXFLOAT)
                                                     options:NSStringDrawingUsesLineFragmentOrigin
                                                  attributes:@{NSFontAttributeName:[UIFont systemFontOfSize:15],
                                                               } context:nil].size.height);
    long charSize = lroundf([UIFont systemFontOfSize:16].lineHeight);
    CGFloat lineCount = (int)ceil( itemHeight / charSize );
    if (lineCount >= 11) {
        itemHeight += (50 +10);
    }else{
        itemHeight += (charSize + 30 +10);
    }
    

    
    return itemHeight;
}

#pragma mark - Gesture
- (IBAction)longPressAction:(UILongPressGestureRecognizer *)sender {

    /*
        长按触发并进入到选择状态
        1. 导航栏的变化，删除动作操作
        2. item 的选择状态的 UI 变化
        3. 
     */
    

    
    _deleteEnabled = YES;
    NSLog(@"开启删除");
}

#pragma mark - UICollectionViewDelegateFlowLayout 
- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout*)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath *)indexPath {
    CGFloat itemWidth = ([UIScreen mainScreen].bounds.size.width - 32)/2 ;
    
    if (indexPath.item == 0) {
        return CGSizeMake(itemWidth, itemWidth);
    }
    
    NSString *contentString = _memoArray[indexPath.item-1];
    
    
    CGFloat itemHeight = ceilf([contentString boundingRectWithSize:CGSizeMake(itemWidth, MAXFLOAT)
                                                           options:NSStringDrawingUsesLineFragmentOrigin
                                                        attributes:@{NSFontAttributeName:[UIFont systemFontOfSize:16],
                                                                     } context:nil].size.height);
    CGSize lineSize = [contentString sizeWithAttributes:@{NSFontAttributeName:[UIFont systemFontOfSize:16]}];
    
    if (itemHeight/lineSize.height >= 11) {
        itemHeight += (50 +10);
    }else {
        itemHeight += (lineSize.height + 30 +10);
    }
    
    

    return CGSizeMake(itemWidth, itemHeight);
}



@end
