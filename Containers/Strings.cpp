#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include <stdio.h>
#include <string.h>


// PROBLEM: Reverse Words - Write a function that reverses the order of the words in a string. 
// Example:
// “Do or do not, there is no try.” --> “try.no is there not, do or Do”.
//bool reverseWords(char str[]) {
//	
//	char* buffer;
//	int slen, tokenReadPos, wordReadPos, wordEnd, writePos = 0;
//	slen = strlen(str);
//	
//	/* Position of the last character is length - 1 */
//	tokenReadPos = slen - 1;
//	buffer = (char*)malloc(slen + 1);
//	
//	if (!buffer)
//		return false; /* memory allocation failed */
//	while (tokenReadPos >= 0) {
//		if (str[tokenReadPos] == ' ') { /* Non-word characters */
//			/* Write character */
//			buffer[writePos++] = str[tokenReadPos--];
//		}
//		else { /* Word characters */
//			/* Store position of end of word */
//			wordEnd = tokenReadPos;
//			
//			/* Scan to next non-word character */
//			while (tokenReadPos >= 0 && str[tokenReadPos] != ' ')
//				tokenReadPos--;
//			
//			/* tokenReadPos went past the start of the word */
//			wordReadPos = tokenReadPos + 1;
//			
//			/* Copy the characters of the word */
//			while (wordReadPos <= wordEnd) {
//				buffer[writePos++] = str[wordReadPos++];
//			}
//		}
//	}
//
//	/* null terminate buffer and copy over str */
//	buffer[writePos] = '\0';
//
//	char* strcpy(char* destination, const char* source);
//
//	//strlcpy(str, buffer, slen + 1);
//	strcpy(str, buffer);
//	free(buffer);
//	return true; /* reverseWords successful */
//}

//int main() {
//
//	char str[] = "Gamze Efendioglu";
//
//	reverseWords(str);
//	return 0;
//}


/*
This solution does not need a temporary buffer 
It doesn’t suffer from dynamic memory overhead
It doesn’t need to copy a result back from a temporary buffer.
*/

void wcReverseString(wchar_t str[], int start, int end) {
	wchar_t temp;
	
	while (end > start) {
		
		/* Exchange characters */
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		
		/* Move indices towards middle */
		start++; end--;
	}
}

void wcReverseWords(wchar_t str[]) {
	int start = 0, end = 0, length;
	length = wcslen(str);

	/* Reverse entire string */
	wcReverseString(str, start, length - 1);
	
	while (end < length) {
		if (str[end] != L' ') { /* Skip non-word characters */
			
			/* Save position of beginning of word */
			start = end;
			
			/* Scan to next non-word character */
			while (end < length && str[end] != L' ')
				end++;
			/* Back up to end of word */
			end--;
			
			/* Reverse word */
			wcReverseString(str, start, end);
		}
		end++; /* Advance to next token */
	}
}

int main() {

	/*
	Wide character string and character literals are prepended with L to distinguish them from regular byte-sized literals.)
	*/
	wchar_t str[] = L"Gamze Efendioglu";
	wcReverseWords(str);
	return 0;
}