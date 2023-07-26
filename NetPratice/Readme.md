</br>
<p align="center">
  <img src="https://github.com/fiborges/42SchoolProjects/blob/main/NetPratice/net_overview-%201.png" height=600 width=500 alt="mask">
</p>
</br>

## IP Address Network Layer

IPv4 vs. IPv6

IPv4 is the more commonly used standard for assigning IP addresses. It consists of a 32-bit number divided into four groups of 8-bit numbers each, separated by periods. For example: 192.168.1.1. However, due to the growth of the Internet and the scarcity of available IPv4 addresses, IPv6 was introduced.

IPv6 uses 128-bit addresses, allowing for a significantly larger number of available addresses. An IPv6 address is represented in eight groups of four hexadecimal digits each, separated by colons. For example: 2001:0db8:85a3:0000:0000:8a2e:0370:7334.

## Public IP Address vs. Private IP Address

A public IP address is one that can be accessed directly over the Internet and is assigned to the network router by the Internet Service Provider (ISP). It allows the internal network to connect to the Internet and be reachable by external devices.

On the other hand, a private IP address is used to address devices within a local network (LAN). These addresses are not routable over the Internet and are used for internal communication between devices within the local network. Private IP addresses are reserved for internal networks and cannot be used on the public Internet.

The ranges of private IP addresses are:

192.168.0.0 - 192.168.255.255 (65,536 IP addresses)
172.16.0.0 - 172.31.255.255 (1,048,576 IP addresses)
10.0.0.0 - 10.255.255.255 (16,777,216 IP addresses)


##Subnet Mask: Network Layer
A subnet mask is used to determine which bits of an IP address belong to the network portion and which bits belong to the host portion. This mask is used to calculate the size of the network and the range of IP addresses that can be used within a network.

##Finding the Network Address
To find the network address, we apply the subnet mask to the IP address. The subnet mask is a binary pattern that determines which bits of the IP address are used for the network and which bits are used for the host.

For example, let's take the following IP address and subnet mask:

IP address: 104.198.241.125
Mask: 255.255.255.128

Let's first convert the subnet mask to its binary form:

Subnet Mask: 11111111.11111111.11111111.10000000

The bits in the subnet mask that are 1 represent the network address, while the bits that are 0 represent the host address. Now let's convert the IP address to its binary form:

IP address: 01101000.11000110.11110001.01111101

We can now apply the subnet mask to the IP address using a bitwise AND operation to find the network address:

Network Address: 01101000.11000110.11110001.00000000

This translates to a network address of 104.198.241.0.

Finding the Range of Host Addresses
To determine the range of host addresses that can be used within the network, we need to identify the bits dedicated to the host address in the IP address.

Continuing from the previous example:

IP address: 01101000.11000110.11110001.01111101
Subnet Mask: 11111111.11111111.11111111.10000000

The range of host addresses is expressed through the last 7 bits of the subnet mask, which are all 0. Therefore, the range of host addresses is:

Binary: 0000000 - 1111111
Decimal: 0 - 127

To get the range of possible IP addresses for our network, we add the range of host addresses to the network address. Our range of possible IP addresses becomes 104.198.241.0 - 104.198.241.127.

However, the extremities of the range are reserved for specific uses and cannot be assigned to a network interface:

104.198.241.0: Reserved to represent the network address.
104.198.241.127: Reserved as the broadcast address; used to send packets to all hosts of a network.
Therefore, our actual IP range becomes 104.198.241.1 - 104.198.241.126, which could be found using an IP calculator.

## CIDR Notation (/24)
The subnet mask can also be represented using Classless Inter-Domain Routing (CIDR) notation. In this notation, the mask is represented as a slash "/", followed by the number of bits that serve as the network address.

In the example above, the subnet mask 255.255.255.128 is equivalent to a mask of /25 using CIDR notation, as 25 bits out of the total 32 bits represent the network address.


## Switch: Data Link Layer
A switch is a networking device that operates at the data link layer of the OSI model. It is used to connect multiple devices together within a single local area network (LAN). Unlike a router, a switch does not have any interfaces for connecting to different networks; instead, it focuses on distributing data packets only within its local network.

When a device wants to communicate with another device on the same network, it sends a data packet to the switch. The switch then examines the destination MAC (Media Access Control) address of the packet and uses its MAC address table to determine which port the packet should be forwarded to. By doing so, the switch efficiently directs the data packet only to the appropriate device, preventing unnecessary broadcasting to all devices like a hub would do.

Switches enable full-duplex communication, meaning devices can send and receive data simultaneously without collisions. This enhances network performance and reduces network congestion, making switches a fundamental component of modern Ethernet networks.

## Router: Network Layer
A router is a networking device that operates at the network layer of the OSI model. Its primary function is to connect multiple networks together, allowing data packets to be routed between them. Routers make decisions on how to forward packets based on the destination IP address found in the packet's header.

When a data packet arrives at a router, the router examines the destination IP address and checks its routing table to determine the best path for the packet to reach its destination. The routing table contains information about various networks and the next-hop router that should be used to reach each network.

Routers use various routing protocols to share information about network topology with other routers, enabling them to build and maintain accurate routing tables. This process ensures that data packets take the most efficient path to their destination across multiple networks.

By connecting different networks, routers enable communication between devices located in different LANs or across the Internet. They provide the essential functionality that enables data to traverse from source to destination across vast and complex networks.

## Routing Table
A routing table is a data structure stored within a router or a network host that contains information about the available routes to specific network destinations. It is a critical component of the routing process, as it guides the router on where to send data packets.

Each entry in the routing table consists of two main elements:

Destination: This specifies a network address representing the destination network for which the route is defined.

Next Hop: The next hop refers to the next closest router through which the data packet should be forwarded to reach the destination network.

Routers use the information in the routing table to determine the best path for forwarding data packets. When a packet arrives at a router, it looks at the destination IP address and searches the routing table for a matching entry. If a match is found, the router forwards the packet according to the information in the routing table.

The routing table is continuously updated through various routing protocols, ensuring that routers can adapt to changes in the network topology and maintain efficient data routing. Proper management of the routing table is crucial for the overall performance and stability of a network.

## Another important Topics

## DNS (Domain Name System)
DNS is a system that translates human-readable domain names (e.g., www.example.com) into IP addresses. It enables us to access websites and other resources using easy-to-remember names instead of numerical IP addresses.

Explanation:
The Domain Name System (DNS) is a critical component of the internet that acts like a phone book, translating user-friendly domain names into numeric IP addresses. When you enter a URL in your web browser, the DNS server associated with your network looks up the corresponding IP address, allowing your device to connect to the desired website or service.

## DHCP (Dynamic Host Configuration Protocol)
DHCP is a network protocol that automatically assigns IP addresses and other network configuration settings to devices on a network. It simplifies the process of network configuration and management.

Explanation:
Dynamic Host Configuration Protocol (DHCP) is a network protocol that enables devices to obtain IP addresses, subnet masks, gateway addresses, and other network configuration parameters automatically. Instead of manually configuring each device on the network, DHCP servers dynamically allocate and manage IP addresses, making network administration more efficient.

## NAT (Network Address Translation)
NAT is a technique used to map private IP addresses to a single public IP address. It allows multiple devices within a private network to share a single public IP address, which helps conserve IPv4 addresses.

Explanation:
Network Address Translation (NAT) is a method that allows multiple devices on a local network to share a single public IP address. NAT plays a crucial role in extending the life of IPv4 addresses by translating private IP addresses used within a local network to a single public IP address used for internet communication.

## Firewalls
Firewalls are security devices or software that monitor and control incoming and outgoing network traffic based on predefined security rules. They act as a barrier between internal and external networks, protecting against unauthorized access and potential threats.

Explanation:
Firewalls are an essential part of network security. They examine network packets and determine whether to allow or block them based on a set of predetermined rules. Firewalls can be either hardware appliances or software running on dedicated servers, routers, or individual devices.

## VPN (Virtual Private Network)
VPNs extend a private network across a public network (usually the internet) to enable secure remote access to resources. They encrypt traffic between the user's device and the VPN server, ensuring privacy and data integrity.

Explanation:
A Virtual Private Network (VPN) provides a secure and encrypted connection between a user's device and a remote network. It allows users to access resources on the private network as if they were directly connected to it, even when they are physically located outside the network.

## Wireless Networking
Understanding wireless protocols like Wi-Fi (IEEE 802.11 standards) and their security mechanisms (WPA, WPA2, WPA3) is essential, as wireless networks are prevalent in modern networking environments.

Explanation:
Wireless networking, often referred to as Wi-Fi, allows devices to connect to a network without using physical cables. The IEEE 802.11 family of standards defines various Wi-Fi protocols, providing different speeds and ranges. Securing wireless networks is crucial to prevent unauthorized access and protect sensitive data.

## Network Topologies
Different network topologies, such as star, bus, ring, and mesh, determine how devices are interconnected in a network. Each topology has its advantages and disadvantages in terms of scalability and fault tolerance.

Explanation:
Network topology refers to the physical or logical layout of devices and connections in a network. Different topologies offer varying levels of reliability, scalability, and ease of maintenance. Common topologies include the star topology, where all devices connect to a central hub; the bus topology, where devices connect to a single communication line; and the mesh topology, where devices connect directly to every other device.

## Network Devices
Besides routers and switches, there are other crucial networking devices like network bridges, gateways, repeaters, and access points that serve specific purposes in network communication.

Explanation:
In addition to routers and switches, various network devices perform specific functions to facilitate communication within and between networks. Network bridges connect separate network segments, gateways interconnect different network protocols, repeaters extend the range of network signals, and access points enable wireless connectivity.

## Quality of Service (QoS)
QoS is a set of techniques to manage and prioritize network traffic to ensure better performance for critical applications and services.

Explanation:
Quality of Service (QoS) mechanisms allow network administrators to prioritize certain types of traffic over others. This ensures that critical applications like voice and video conferencing receive sufficient bandwidth and low latency, even during times of high network utilization.

## IPv6 Adoption
Given the exhaustion of IPv4 addresses, the transition and adoption of IPv6 are crucial to accommodate the growing number of devices on the internet.

Explanation:
With the proliferation of internet-connected devices, the number of available IPv4 addresses has become insufficient. IPv6, with its larger address space, provides a solution to this problem. IPv6 adoption is vital to ensure the continued growth of the internet and support the increasing number of connected devices worldwide.


