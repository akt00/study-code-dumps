
use std::ops::{Index, IndexMut};

pub mod greetings {
    pub fn hello_world() {
        println!{"hello world"};
    }   
}

pub mod scripts {
    pub fn bubble_sort<V>(size: usize, array: &mut V)
    where 
        V: Index<usize> + IndexMut<usize>,
        V::Output: Eq + PartialEq + PartialOrd + Ord + Sized + Clone,
    {
        for i in 0..size {
            for j in 1..size {
                if array[j-1] > array[j] {
                    let tmp = array[j-1].clone();
                    array[j-1] = array[j].clone();
                    array[j] = tmp
                }
            }
        }
    }
}

pub mod linked_list {
    type NodePtr = Option<Box<Node>>;

    struct Node {
        value: i32,
        next: NodePtr,
    }

    pub struct Link {
        head: NodePtr,
    }

    impl Link {
        pub fn add(&mut self, val: i32) {
            let new_node = Box::new(Node {
                value: val,
                next: self.head.take(),
            });
            self.head = Some(new_node);
        }
    }
}

pub mod macro_scripts {
    #[macro_export]
    macro_rules! show {
        ($arg: expr) => {
            println!("{}", $arg):
        }
    }
}

pub mod unsafe_scripts {
    use std::alloc::{self, Layout};
    
    pub unsafe fn pointer_of_pointer(arg: *mut *mut u8) {
        let layout =  Layout::new::<i32>();
        *arg = alloc::alloc(layout);
    }

    pub unsafe fn dynamic_array() {
        let layout = Layout::array::<i32>(10).unwrap();
        let new_mem = alloc::alloc(layout);
        *new_mem.add(2) = 11;
        println!("{}", *new_mem.add(2));
        alloc::dealloc(new_mem, layout);
    }
}

pub mod utils {
    use std::any;
    pub fn type_id<T>(_: &T) {
        println!("{}", any::type_name::<T>());
    }
}
