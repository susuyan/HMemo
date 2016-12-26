//
//  HEditViewController.m
//  HMemo
//
//  Created by 余胜民 on 06/12/2016.
//  Copyright © 2016 susuyan. All rights reserved.
//

#import "HEditViewController.h"
#import "UIColor+RGBValues.h"
#import <YYText.h>
@interface HEditViewController ()

@property (strong, nonatomic) IBOutlet YYTextView *textView;


@end

@implementation HEditViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [self setupTextView];
    
}

- (void)setupTextView {
    

    NSMutableAttributedString *text = [[NSMutableAttributedString alloc] initWithString:@"Hello world ！"];
    text.yy_font = [UIFont systemFontOfSize:20];
    text.yy_lineSpacing = 4;
    text.yy_color = [UIColor colorFromHexRGB:@"646464"];
    

    _textView.textContainerInset = UIEdgeInsetsMake(10, 10, 10, 10);
    _textView.attributedText = text;


}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)backAndSaveAction:(UIButton *)sender {
    if (self.presentingViewController) {
        [self dismissViewControllerAnimated:YES completion:nil];
    } else {
        [self.navigationController popViewControllerAnimated:YES];
    }
    
}

@end
