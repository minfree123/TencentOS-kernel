/* SPDX-License-Identifier: GPL-2.0-or-later */

#ifndef _LINUX_DROPREASON_H
#define _LINUX_DROPREASON_H

/**
 * enum skb_drop_reason - the reasons of skb drops
 *
 * The reason of skb drop, which is used in kfree_skb_reason().
 */
enum skb_drop_reason {
	/**
	 * @SKB_NOT_DROPPED_YET: skb is not dropped yet (used for no-drop case)
	 */
	SKB_NOT_DROPPED_YET = 0,
	/** @SKB_DROP_REASON_NOT_SPECIFIED: drop reason is not specified */
	SKB_DROP_REASON_NOT_SPECIFIED,
	/** @SKB_DROP_REASON_NO_SOCKET: socket not found */
	SKB_DROP_REASON_NO_SOCKET,
	/** @SKB_DROP_REASON_PKT_TOO_SMALL: packet size is too small */
	SKB_DROP_REASON_PKT_TOO_SMALL,
	/** @SKB_DROP_REASON_TCP_CSUM: TCP checksum error */
	SKB_DROP_REASON_TCP_CSUM,
	/** @SKB_DROP_REASON_SOCKET_FILTER: dropped by socket filter */
	SKB_DROP_REASON_SOCKET_FILTER,
	/** @SKB_DROP_REASON_UDP_CSUM: UDP checksum error */
	SKB_DROP_REASON_UDP_CSUM,
	/** @SKB_DROP_REASON_NETFILTER_DROP: dropped by netfilter */
	SKB_DROP_REASON_NETFILTER_DROP,
	/**
	 * @SKB_DROP_REASON_OTHERHOST: packet don't belong to current host
	 * (interface is in promisc mode)
	 */
	SKB_DROP_REASON_OTHERHOST,
	/** @SKB_DROP_REASON_IP_CSUM: IP checksum error */
	SKB_DROP_REASON_IP_CSUM,
	/**
	 * @SKB_DROP_REASON_IP_INHDR: there is something wrong with IP header (see
	 * IPSTATS_MIB_INHDRERRORS)
	 */
	SKB_DROP_REASON_IP_INHDR,
	/**
	 * @SKB_DROP_REASON_IP_RPFILTER: IP rpfilter validate failed. see the
	 * document for rp_filter in ip-sysctl.rst for more information
	 */
	SKB_DROP_REASON_IP_RPFILTER,
	/**
	 * @SKB_DROP_REASON_UNICAST_IN_L2_MULTICAST: destination address of L2 is
	 * multicast, but L3 is unicast.
	 */
	SKB_DROP_REASON_UNICAST_IN_L2_MULTICAST,
	/** @SKB_DROP_REASON_XFRM_POLICY: xfrm policy check failed */
	SKB_DROP_REASON_XFRM_POLICY,
	/** @SKB_DROP_REASON_IP_NOPROTO: no support for IP protocol */
	SKB_DROP_REASON_IP_NOPROTO,
	/** @SKB_DROP_REASON_SOCKET_RCVBUFF: socket receive buff is full */
	SKB_DROP_REASON_SOCKET_RCVBUFF,
	/**
	 * @SKB_DROP_REASON_PROTO_MEM: proto memory limition, such as udp packet
	 * drop out of udp_memory_allocated.
	 */
	SKB_DROP_REASON_PROTO_MEM,
	/**
	 * @SKB_DROP_REASON_TCP_MD5NOTFOUND: no MD5 hash and one expected,
	 * corresponding to LINUX_MIB_TCPMD5NOTFOUND
	 */
	SKB_DROP_REASON_TCP_MD5NOTFOUND,
	/**
	 * @SKB_DROP_REASON_TCP_MD5UNEXPECTED: MD5 hash and we're not expecting
	 * one, corresponding to LINUX_MIB_TCPMD5UNEXPECTED
	 */
	SKB_DROP_REASON_TCP_MD5UNEXPECTED,
	/**
	 * @SKB_DROP_REASON_TCP_MD5FAILURE: MD5 hash and its wrong, corresponding
	 * to LINUX_MIB_TCPMD5FAILURE
	 */
	SKB_DROP_REASON_TCP_MD5FAILURE,
	/**
	 * @SKB_DROP_REASON_SOCKET_BACKLOG: failed to add skb to socket backlog (
	 * see LINUX_MIB_TCPBACKLOGDROP)
	 */
	SKB_DROP_REASON_SOCKET_BACKLOG,
	/** @SKB_DROP_REASON_TCP_FLAGS: TCP flags invalid */
	SKB_DROP_REASON_TCP_FLAGS,
	/**
	 * @SKB_DROP_REASON_TCP_ZEROWINDOW: TCP receive window size is zero,
	 * see LINUX_MIB_TCPZEROWINDOWDROP
	 */
	SKB_DROP_REASON_TCP_ZEROWINDOW,
	/**
	 * @SKB_DROP_REASON_TCP_OLD_DATA: the TCP data reveived is already
	 * received before (spurious retrans may happened), see
	 * LINUX_MIB_DELAYEDACKLOST
	 */
	SKB_DROP_REASON_TCP_OLD_DATA,
	/**
	 * @SKB_DROP_REASON_TCP_OVERWINDOW: the TCP data is out of window,
	 * the seq of the first byte exceed the right edges of receive
	 * window
	 */
	SKB_DROP_REASON_TCP_OVERWINDOW,
	/**
	 * @SKB_DROP_REASON_TCP_OFOMERGE: the data of skb is already in the ofo
	 * queue, corresponding to LINUX_MIB_TCPOFOMERGE
	 */
	SKB_DROP_REASON_TCP_OFOMERGE,
	/**
	 * @SKB_DROP_REASON_TCP_RFC7323_PAWS: PAWS check, corresponding to
	 * LINUX_MIB_PAWSESTABREJECTED
	 */
	SKB_DROP_REASON_TCP_RFC7323_PAWS,
	/** @SKB_DROP_REASON_TCP_INVALID_SEQUENCE: Not acceptable SEQ field */
	SKB_DROP_REASON_TCP_INVALID_SEQUENCE,
	/** @SKB_DROP_REASON_TCP_RESET: Invalid RST packet */
	SKB_DROP_REASON_TCP_RESET,
	/**
	 * @SKB_DROP_REASON_TCP_INVALID_SYN: Incoming packet has unexpected
	 * SYN flag
	 */
	SKB_DROP_REASON_TCP_INVALID_SYN,
	/** @SKB_DROP_REASON_TCP_CLOSE: TCP socket in CLOSE state */
	SKB_DROP_REASON_TCP_CLOSE,
	/** @SKB_DROP_REASON_TCP_FASTOPEN: dropped by FASTOPEN request socket */
	SKB_DROP_REASON_TCP_FASTOPEN,
	/** @SKB_DROP_REASON_TCP_OLD_ACK: TCP ACK is old, but in window */
	SKB_DROP_REASON_TCP_OLD_ACK,
	/** @SKB_DROP_REASON_TCP_TOO_OLD_ACK: TCP ACK is too old */
	SKB_DROP_REASON_TCP_TOO_OLD_ACK,
	/**
	 * @SKB_DROP_REASON_TCP_ACK_UNSENT_DATA: TCP ACK for data we haven't
	 * sent yet
	 */
	SKB_DROP_REASON_TCP_ACK_UNSENT_DATA,
	/** @SKB_DROP_REASON_TCP_OFO_QUEUE_PRUNE: pruned from TCP OFO queue */
	SKB_DROP_REASON_TCP_OFO_QUEUE_PRUNE,
	/** @SKB_DROP_REASON_TCP_OFO_DROP: data already in receive queue */
	SKB_DROP_REASON_TCP_OFO_DROP,
	/** @SKB_DROP_REASON_IP_OUTNOROUTES: route lookup failed */
	SKB_DROP_REASON_IP_OUTNOROUTES,
	/**
	 * @SKB_DROP_REASON_BPF_CGROUP_EGRESS: dropped by BPF_PROG_TYPE_CGROUP_SKB
	 * eBPF program
	 */
	SKB_DROP_REASON_BPF_CGROUP_EGRESS,
	/** @SKB_DROP_REASON_IPV6DISABLED: IPv6 is disabled on the device */
	SKB_DROP_REASON_IPV6DISABLED,
	/** @SKB_DROP_REASON_NEIGH_CREATEFAIL: failed to create neigh entry */
	SKB_DROP_REASON_NEIGH_CREATEFAIL,
	/** @SKB_DROP_REASON_NEIGH_FAILED: neigh entry in failed state */
	SKB_DROP_REASON_NEIGH_FAILED,
	/** @SKB_DROP_REASON_NEIGH_QUEUEFULL: arp_queue for neigh entry is full */
	SKB_DROP_REASON_NEIGH_QUEUEFULL,
	/** @SKB_DROP_REASON_NEIGH_DEAD: neigh entry is dead */
	SKB_DROP_REASON_NEIGH_DEAD,
	/** @SKB_DROP_REASON_TC_EGRESS: dropped in TC egress HOOK */
	SKB_DROP_REASON_TC_EGRESS,
	/**
	 * @SKB_DROP_REASON_QDISC_DROP: dropped by qdisc when packet outputting (
	 * failed to enqueue to current qdisc)
	 */
	SKB_DROP_REASON_QDISC_DROP,
	/**
	 * @SKB_DROP_REASON_CPU_BACKLOG: failed to enqueue the skb to the per CPU
	 * backlog queue. This can be caused by backlog queue full (see
	 * netdev_max_backlog in net.rst) or RPS flow limit
	 */
	SKB_DROP_REASON_CPU_BACKLOG,
	/** @SKB_DROP_REASON_XDP: dropped by XDP in input path */
	SKB_DROP_REASON_XDP,
	/** @SKB_DROP_REASON_TC_INGRESS: dropped in TC ingress HOOK */
	SKB_DROP_REASON_TC_INGRESS,
	/** @SKB_DROP_REASON_UNHANDLED_PROTO: protocol not implemented or not supported */
	SKB_DROP_REASON_UNHANDLED_PROTO,
	/** @SKB_DROP_REASON_SKB_CSUM: sk_buff checksum computation error */
	SKB_DROP_REASON_SKB_CSUM,
	/** @SKB_DROP_REASON_SKB_GSO_SEG: gso segmentation error */
	SKB_DROP_REASON_SKB_GSO_SEG,
	/**
	 * @SKB_DROP_REASON_SKB_UCOPY_FAULT: failed to copy data from user space,
	 * e.g., via zerocopy_sg_from_iter() or skb_orphan_frags_rx()
	 */
	SKB_DROP_REASON_SKB_UCOPY_FAULT,
	/** @SKB_DROP_REASON_DEV_HDR: device driver specific header/metadata is invalid */
	SKB_DROP_REASON_DEV_HDR,
	/**
	 * @SKB_DROP_REASON_DEV_READY: the device is not ready to xmit/recv due to
	 * any of its data structure that is not up/ready/initialized,
	 * e.g., the IFF_UP is not set, or driver specific tun->tfiles[txq]
	 * is not initialized
	 */
	SKB_DROP_REASON_DEV_READY,
	/** @SKB_DROP_REASON_FULL_RING: ring buffer is full */
	SKB_DROP_REASON_FULL_RING,
	/** @SKB_DROP_REASON_NOMEM: error due to OOM */
	SKB_DROP_REASON_NOMEM,
	/**
	 * @SKB_DROP_REASON_HDR_TRUNC: failed to trunc/extract the header from
	 * networking data, e.g., failed to pull the protocol header from
	 * frags via pskb_may_pull()
	 */
	SKB_DROP_REASON_HDR_TRUNC,
	/**
	 * @SKB_DROP_REASON_TAP_FILTER: dropped by (ebpf) filter directly attached
	 * to tun/tap, e.g., via TUNSETFILTEREBPF
	 */
	SKB_DROP_REASON_TAP_FILTER,
	/**
	 * @SKB_DROP_REASON_TAP_TXFILTER: dropped by tx filter implemented at
	 * tun/tap, e.g., check_filter()
	 */
	SKB_DROP_REASON_TAP_TXFILTER,
	/** @SKB_DROP_REASON_ICMP_CSUM: ICMP checksum error */
	SKB_DROP_REASON_ICMP_CSUM,
	/**
	 * @SKB_DROP_REASON_INVALID_PROTO: the packet doesn't follow RFC 2211,
	 * such as a broadcasts ICMP_TIMESTAMP
	 */
	SKB_DROP_REASON_INVALID_PROTO,
	/**
	 * @SKB_DROP_REASON_IP_INADDRERRORS: host unreachable, corresponding to
	 * IPSTATS_MIB_INADDRERRORS
	 */
	SKB_DROP_REASON_IP_INADDRERRORS,
	/**
	 * @SKB_DROP_REASON_IP_INNOROUTES: network unreachable, corresponding to
	 * IPSTATS_MIB_INADDRERRORS
	 */
	SKB_DROP_REASON_IP_INNOROUTES,
	/**
	 * @SKB_DROP_REASON_PKT_TOO_BIG: packet size is too big (maybe exceed the
	 * MTU)
	 */
	SKB_DROP_REASON_PKT_TOO_BIG,
	/**
	 * @SKB_DROP_REASON_SOCKET_DESTROYED: socket is destroyed and the
	 * skb in its receive or send queue are all dropped
	 */
	SKB_DROP_REASON_SOCKET_DESTROYED,
	/**
	 * @SKB_DROP_REASON_TCP_PAWSACTIVEREJECTED: PAWS check failed for
	 * active TCP connection, corresponding to
	 * LINUX_MIB_PAWSACTIVEREJECTED
	 */
	SKB_DROP_REASON_TCP_PAWSACTIVEREJECTED,
	/**
	 * @SKB_DROP_REASON_TCP_LINGER: dropped because of the setting of
	 * TCP socket option TCP_LINGER2, corresponding to
	 * LINUX_MIB_TCPABORTONLINGER
	 */
	SKB_DROP_REASON_TCP_LINGER,
	/**
	 * @SKB_DROP_REASON_LISTENOVERFLOWS: accept queue of the listen
	 * socket is full, corresponding to LINUX_MIB_LISTENOVERFLOWS
	 */
	SKB_DROP_REASON_LISTENOVERFLOWS,
	/**
	 * @SKB_DROP_REASON_TCP_REQQFULLDROP: request queue of the listen
	 * socket is full, corresponding to LINUX_MIB_TCPREQQFULLDROP
	 */
	SKB_DROP_REASON_TCP_REQQFULLDROP,
	/**
	 * @SKB_DROP_REASON_TIMEWAIT: socket is in time-wait state and all
	 * packet that received will be treated as 'drop', except a good
	 * 'SYN' packet
	 */
	SKB_DROP_REASON_TIMEWAIT,
	/** @SKB_DROP_REASON_LSM: dropped by LSM */
	SKB_DROP_REASON_LSM,
	/**
	 * @SKB_DROP_REASON_MAX: the maximum of drop reason, which shouldn't be
	 * used as a real 'reason'
	 */
	SKB_DROP_REASON_MAX,
};

#define SKB_DR_INIT(name, reason)				\
	enum skb_drop_reason name = SKB_DROP_REASON_##reason
#define SKB_DR(name)						\
	SKB_DR_INIT(name, NOT_SPECIFIED)
#define SKB_DR_SET(name, reason)				\
	(name = SKB_DROP_REASON_##reason)
#define SKB_DR_OR(name, reason)					\
	do {							\
		if (name == SKB_DROP_REASON_NOT_SPECIFIED ||	\
		    name == SKB_NOT_DROPPED_YET)		\
			SKB_DR_SET(name, reason);		\
	} while (0)

extern const char * const drop_reasons[];

#endif
