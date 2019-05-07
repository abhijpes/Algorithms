package main

import (
	"fmt"
	"strconv"
)

type Node struct {
	digit int
	next  *Node
}

func addLinkedLists(head1 *Node, tail1 *Node, head2 *Node, tail2 *Node) (*Node, *Node) {
	if head1 == nil {
		return head2, tail2
	} else if head2 == nil {
		return head1, tail1
	} else {
		var head_result *Node = nil
		var tail_result *Node = head_result
		head1, tail1 = reverseLinkedList(head1, tail1)
		head2, tail2 = reverseLinkedList(head2, tail2)
		i := head1
		j := head2
		var sum, carry int = 0, 0

		for {
			//fmt.Printf("Carry for next step: %d\n", carry)
			result := new(Node)

			sum = (*i).digit + (*j).digit + carry
			(*result).digit = sum % 10
			carry = sum / 10
			head_result, tail_result = addNode(head_result, tail_result, result)
			i = (*i).next
			j = (*j).next
			if i == nil || j == nil {
				//fmt.Printf("Reached here")
				(*result).digit = carry
				//fmt.Printf("This is the final node in the LL: %v\n", result)
				head_result, tail_result = addNode(head_result, tail_result, result)
				break
			}

		}
		return head_result, tail_result
	}

}
func reverseLinkedList(head *Node, tail *Node) (*Node, *Node) {
	if head == nil {
		return nil, nil
	}
	var prev, post *Node
	prev = nil
	post = (*head).next
	for head != nil {
		//fmt.Println("Iteration start")
		//fmt.Printf("prev : %v , head : %v , post : %v\n", prev, head, post)
		(*head).next = prev
		if prev == nil {
			//Possibly the first iteration; place the tail here
			tail = head
		}
		prev = head
		head = post
		if post != nil {
			post = (*post).next
		}
	}
	head = prev
	return head, tail
}

func traverseLinkedList(head *Node, tail *Node) {
	for iter := head; iter != nil; iter = (*iter).next {
		fmt.Printf("%d\t", (*iter).digit)
	}
	fmt.Println()
}

func IntToList(num int) []int {
	var digitList []int
	for num > 0 {
		digit := num % 10
		digitList = append(digitList, digit)
		num = num / 10
	}
	return digitList
}

func addNode(head *Node, tail *Node, node *Node) (*Node, *Node) {
	if tail != nil {
		(*tail).next = node
		tail = (*tail).next

	} else {
		//New node
		head = node
		tail = node
	}
	return head, tail
}
func createLinkList(num int) (*Node, *Node) {
	var head, tail *Node
	list := IntToList(num)
	for i := 0; i < len(list); i++ {
		node := new(Node)
		(*node).digit = list[i]
		//fmt.Printf("%v", node)
		//node := &Node{list[i], nil}
		// Point to note - Zero value of
		head, tail = addNode(head, tail, node)
	}
	//traverseLinkedList(head, tail)
	newHead, newTail := reverseLinkedList(head, tail)
	return newHead, newTail
}

func main() {
	var mindigits, num1, num2 int
	var valid bool
	fmt.Println("What's the minimum number of digits you like to deal with?")
	fmt.Scanf("%d", &mindigits)
	for !valid {
		valid = true
		fmt.Println("Enter 1st Operand")
		fmt.Scanf("%d", &num1)
		if len(strconv.Itoa(num1)) < mindigits {
			valid = false
			fmt.Println("Incorrect length..Try Again!")
			continue
		}
		fmt.Println("Enter 2nd Operand")
		fmt.Scanf("%d", &num2)
		if len(strconv.Itoa(num2)) < mindigits {
			valid = false
			fmt.Println("Incorrect length..Try Again!")
			continue
		}
	}
	//var num1 *Node = createLinkList(num1)
	//var num2 *Node = createLinkList(num2)
	head1, tail1 := createLinkList(num1)
	head2, tail2 := createLinkList(num2)
	traverseLinkedList(head1, tail1)
	traverseLinkedList(head2, tail2)
	head_r, tail_r := addLinkedLists(head1, tail1, head2, tail2)
	traverseLinkedList(head_r, tail_r)
}
