use arithmetic::stack_parser::{text_to_rpn, stack_calculator};

#[test]
fn case1() {
    let rpn = text_to_rpn("2 * 4 + 8");
    assert_eq!(16.0, stack_calculator(&rpn));
}

#[test]
fn case2() {
    let rpn = text_to_rpn("2 * (4+8)");
    assert_eq!(24.0, stack_calculator(&rpn));
}

#[test]
fn case3() {
    let rpn = text_to_rpn("3*2-11");
    assert_eq!(-5.0, stack_calculator(&rpn));
}

#[test]
fn case4() {
    let rpn = text_to_rpn("(2*5+4)/(3*2+1)");
    assert_eq!(2.0, stack_calculator(&rpn));
}