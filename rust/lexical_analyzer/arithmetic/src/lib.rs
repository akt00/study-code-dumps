pub mod stack_parser {
    pub enum Token {
        Operator(char), // + - * /
        Bracket(char), // ( )
        Number(f32),
    }
    // unary operator is not supported
    pub fn text_to_rpn(text: &str) -> Vec<Token> {
        let mut iter = text.chars().into_iter().peekable();
        let mut v: Vec<Token> = Vec::new();
        loop {
            let ch = iter.next();
            if let Some(i) = ch {
                // parser number
                if i.is_digit(10) {
                    let mut num = i.to_string().clone();
                    while let Some(n) = iter.peek() {
                        if n.is_digit(10) || n == &'.' {
                            num += &n.to_string().clone();
                            iter.next();
                        } else {
                            break;
                        }
                    }
                    v.push(Token::Number(num.parse::<f32>().unwrap()));
                // skip whitespace
                } else if i.is_ascii_whitespace() {
                    continue;
                // parse operators
                } else if i.is_ascii() {
                    match i {
                        '+' | '-' | '*' | '/' => v.push(Token::Operator(i)),
                        '(' | ')' => v.push(Token::Bracket(i)),
                        _ => panic!("invalid input format"),
                    }
                }
            } else {
                break;
            }
        }
        to_rpn(&v,&mut 0)
    }
    
    fn to_rpn(v: &Vec<Token>, idx: &mut usize) -> Vec<Token> {
        let mut rpn: Vec<Token> = Vec::new();
        let mut operators: Vec<Token> = Vec::new();
        while *idx < v.len() {
            let tk = &v[*idx];
            match *tk {
                Token::Number(i) => rpn.push(Token::Number(i)),
                Token::Operator(i) => {
                    match i {
                        '+' | '-' => {
                            if operators.is_empty() {
                                operators.push(Token::Operator(i));
                            } else {
                                while !operators.is_empty() {
                                    rpn.push(operators.pop().unwrap());
                                }
                            }
                        },
                        '*' | '/' => {
                            if operators.is_empty() {
                                *idx += 1;
                                let tmp = &v[*idx];
                                match *tmp {
                                    Token::Number(i) => rpn.push(Token::Number(i)),
                                    Token::Bracket(i) => {
                                        match i {
                                            '(' => {
                                                *idx += 1;
                                                let mut ret = to_rpn(v, idx);
                                                rpn.append(&mut ret)
                                            },
                                            _ => panic!("invalid bracket")
                                        }
                                    },
                                    _ => panic!("invalid format"),
                                }
                                rpn.push(Token::Operator(i));
                            } else {
                                if let Token::Operator(op) = operators.last().unwrap() {
                                    match *op {
                                        '+' | '-' => {
                                            *idx += 1;
                                            let num = &v[*idx];
                                            match *num {
                                                Token::Number(n) => {
                                                    rpn.push(Token::Number(n));
                                                }
                                                _ => panic!("expected a number"),
                                            }
                                            rpn.push(Token::Operator(i))
                                        },
                                        _ => operators.push(Token::Operator(i))
                                    }
                                }
                            }
                        },
                        _ => panic!("invalid operator {i}")
                    }
                },
                Token::Bracket(i) => {
                    match i {
                        '(' => {
                            *idx += 1;
                            let mut ret = to_rpn(v, idx);
                            rpn.append(&mut ret);
                        },
                        ')' => {
                            while !operators.is_empty() {
                                rpn.push(operators.pop().unwrap());
                            }
                            return rpn
                        },
                        _ => panic!("invalid bracket")
                    }
                }
            }
            *idx += 1
        }
        
        while !operators.is_empty() {
            rpn.push(operators.pop().unwrap());
        }
        rpn
    }
    
    // computes on reverse polish notation tokens
    pub fn stack_calculator(v: &Vec<Token>) -> f32 {
        let mut operands: Vec<f32> = Vec::new();
        for tk in v {
            match tk {
                Token::Number(i) => operands.push(*i),
                Token::Operator(i) => {
                    match i {
                        '+' =>  {
                            let res = operands.pop().unwrap() + operands.pop().unwrap();
                            operands.push(res)
                        },
                        '-' =>  {
                            let res = - operands.pop().unwrap() + operands.pop().unwrap();
                            operands.push(res)
                        },
                        '*' => {
                            let res = operands.pop().unwrap() * operands.pop().unwrap();
                            operands.push(res)
                        },
                        '/' => {
                            let right = operands.pop().unwrap();
                            let res = operands.pop().unwrap() / right;
                            operands.push(res)
                        },
                        _ => panic!("invalid operator {}", i)
                    }
                },
                _ => panic!("invalid token")
            }
        }
        assert_eq!(operands.len(), 1);
        operands.pop().unwrap()
    }
}