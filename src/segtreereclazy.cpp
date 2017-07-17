#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAX -1

struct ST {
	int n;
	ll st[4*MAX];
	ll lazy[4*MAX];
	
	/**
	 * Build and init tree
	 */
	void build(ll v[MAX], int s) {
		n = s;
		memset(lazy, 0, sizeof lazy);
		build(1, 0, n-1, v);
	}
	
	void build(int node, int l, int r, ll v[MAX]) {	  	
	  	if (l == r) st[node] = v[l]; // tree node
	  	else {
			int mid = (l+r)/2;
			build(node*2, l, mid, v); // Init left child
			build(node*2+1, mid+1, r, v); // Init right child
	
			st[node] = st[node*2] + st[node*2+1]; // Init root value
		}
	}
	
	void push(int node, int i, int j) {
		if (lazy[node] != 0) { // This node needs to be updated
	   		st[node] += (j-i+1) * lazy[node]; // Update it

			if (i != j) {
				lazy[node*2] += lazy[node]; // Mark child as lazy
				lazy[node*2+1] += lazy[node]; // Mark child as lazy
			}

	   		lazy[node] = 0; // Reset it
	  	}
	}
	
	/**
	 * Increment elements within range [l, r] with value value
	 */
	void update(int l, int r, ll value) {
		update(1, 0, n-1, l, r, value);
	}
	
	void update(int node, int i, int j, int ql, int qr, ll value) {
	  	push(node, i, j);

		if (i > qr || j < ql) // Current segment is not within range [ql, qr]
			return;
		
	  	if (ql <= i && j <= qr) { // Segment is fully within range
			st[node] += (j-i+1) * value;

			if (i != j) { // Not leaf node
				lazy[node*2] += value;
				lazy[node*2+1] += value;
			}

			return;
		}

		int mid = (i+j)/2;
		update(node*2, i, mid, ql, qr, value); // Updating left child
		update(node*2+1, mid+1, j, ql, qr, value); // Updating right child

		st[node] = st[node*2] + st[node*2+1]; // Updating root
	}
	
	/**
	 * Query tree to get value within range [l, r]
	 */
	ll query(int l, int r) {
		return query(1, 0, n-1, l, r);
	}
	
	ll query(int node, int i, int j, int ql, int qr) {
		if (i > qr || j < ql) return 0; // Out of range

		push(node, i, j);
		
		if (ql <= i && j <= qr) // Current segment is totally within range [l, r]
			return st[node];

		int mid = (i+j)/2;
		ll q1 = query(node*2, i, mid, ql, qr); // Query left child
		ll q2 = query(node*2+1, mid+1, j, ql, qr); // Query right child

		ll res = q1 + q2; // Return final result
	
		return res;
	}
};
