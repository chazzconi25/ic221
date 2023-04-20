#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]){

	struct addrinfo *result;		// to store results
	struct addrinfo *cur_result;    // to store results
	struct addrinfo hints;			// to indicate information we want
	struct sockaddr_in *saddr;		// to reference address (IPv4)
	struct sockaddr_in6 *saddr6;	// to reference address (IPv6)
	int s; 							// for error checking

	memset(&hints,0,sizeof(struct addrinfo));  //zero out hints
	hints.ai_family = AF_UNSPEC; //we only want IPv4 & IPv6 addresses	
	
	//Convert the hostname to an address
	if( (s = getaddrinfo(argv[1], NULL, &hints, &result)) != 0){
		fprintf(stderr, "getaddrinfo: %s\n",gai_strerror(s));
		exit(1);
	}

	for(cur_result = result; cur_result != NULL; cur_result = cur_result->ai_next){
		if(cur_result->ai_protocol == IPPROTO_TCP 
			&& cur_result->ai_family == AF_INET) {
			//convert generic socket address to inet socket address
			saddr = (struct sockaddr_in *) cur_result->ai_addr;
			//print the address
			printf("%s has address %s\n", argv[1], inet_ntoa(saddr->sin_addr));
			
		}
		if(cur_result->ai_protocol == IPPROTO_TCP
			&& cur_result->ai_family == AF_INET6) {
			//convert generic socket address to inet socket address
			saddr6 = (struct sockaddr_in6 *) cur_result->ai_addr;
			//string to store address and print the address
			char str[INET6_ADDRSTRLEN];
			printf("%s has IPv6 address %s\n", argv[1], inet_ntop(AF_INET6, &saddr6->sin6_addr, str, INET6_ADDRSTRLEN));
		}
	}

	//free the addrinfo struct
	freeaddrinfo(result);
	//TODO: Complete the lab
	//
	// Outline:
	//   - set up the hints
	//   - perform the getaddrinfo()
	//   - iterate over the results
	//   - print the resolved ip address
	//   - clean up the results with freaddrinfo()
	
}
