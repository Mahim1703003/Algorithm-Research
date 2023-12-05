#include<bits/stdc++.h>
#include<cmath>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;



#define debug printf("Debug\n");
#define ull unsigned long long

#define pi acos(-1.0)
#define mod 1000000007

#define _fastio  ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define in_fre  freopen("in.txt", "r", stdin);
#define out_fre freopen("out.txt", "w", stdout);

#define en '\n'
#define ll long long
#define sz 1000006


#include<chrono>
#include<ctime>

using namespace std;
using namespace std::chrono;

void PRINT4(ll b,ll e);
void nazum_sort_modified();
void merge_sort(ll k);
void nazum_merge(ll low1,ll up1,ll low2,ll up2);

ll n=100000;
ll quicknum[sz], mergenum[sz], stlnum[sz],radixnum[sz],anazumm[sz],bnazumm[sz],lista[sz],listb[sz];
char listch[sz];



struct Node{
    ll l,r;
    bool ty;
};


/*OUR algo start*/
ll a0[sz];
Node r0[sz];

void PRINT0(ll b,ll e){
    ll f=0;
    for(ll i=b+1;i<=e;i++){
        //cout<<a0[i]<<' ';
        if(a0[i]<a0[i-1]) f++;
    }
    cout<<f<<en;
}


void REVERSE0(ll l, ll r){
    ll in=0;
    ll xx=(l+r)/2;
    for(ll i=l;i<=xx;i++){
        swap(a0[l+in],a0[r-in]);
        in++;
    }
}

void CONQUER0(Node x, Node y){
    ll temp[y.r-x.l+10];
    ll p1=x.l,p2=y.l,p3=0;
    while(p1<=x.r&&p2<=y.r){
        if(a0[p1]<=a0[p2]){
            p3++;temp[p3]=a0[p1];p1++;
        }
        else{
            p3++;temp[p3]=a0[p2];p2++;
        }
    }
    while(p1<=x.r){
        p3++;temp[p3]=a0[p1];p1++;
    }
    while(p2<=y.r){
        p3++;temp[p3]=a0[p2];p2++;
    }

    for(ll i=x.l;i<=y.r;i++){
        a0[i]=temp[i-x.l+1];
    }

}

Node DEVIDE0(ll b,ll e){
    if(b==e){
        Node x;
        x.l=r0[b].l,x.r=r0[b].r;
        return x;
    }
    ll mid=(b+e)/2;
    Node x,y;
    x=DEVIDE0(b,mid);
    y=DEVIDE0(mid+1,e);
    CONQUER0(x,y);
    x.r=y.r;
    return x;
}

void NAZUMSORT0(ll Begin,ll End){
    ll tot=0;
    Node x;
    x.l=Begin,x.r=Begin;
    for(ll i=Begin+1;i<=End;i++){
        if(a0[i]<=a0[i-1]){
            x.r=i;
        }
        else{
            REVERSE0(x.l,x.r);
            x.l=i,x.r=i;
        }
    }
    REVERSE0(x.l,x.r);

    x.l=Begin,x.r=Begin;
    for(ll i=Begin+1;i<=End;i++){
        if(a0[i]>=a0[i-1]){
            x.r=i;
        }
        else{
            tot++;
            r0[tot]=x;
            x.l=i,x.r=i;
        }
    }
    tot++;
    r0[tot]=x;
    DEVIDE0(1,tot);
    //cout<<tot<<en;
    //cout<<r0[1].l<<' '<<r0[1].r<<en;

}
/*OUR algo end*/



/*QUICK +Our algo   start*/

ll a[sz];
Node r[sz];





ll c1=0;

ll NPARTITION (ll low, ll high)
{

    ll pivot = a[high];
    //a[(low+high)/2];
    //swap(a[(low+high)/2],a[high]);
    ll i = (low - 1);

    for (ll j = low; j <= high - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1],a[high]);
    return (i + 1);
}

void NQUICK(ll low, ll high)
{
    if (low < high)
    {

        ll pivot = NPARTITION(low, high);
        NQUICK(low, pivot - 1);
        NQUICK(pivot + 1, high);
    }

    /*for(ll i=low;i<=high;i++){
        for(ll j=i+1;j<=high;j++){
            if(a[j]<a[i]) swap(a[i],a[j]);
        }
    }*/

    /*ll i, key, j;
    for (i = low+1; i <=high; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= low && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }*/

}



void PRINT(ll b,ll e){
	/*for(ll i=b;i<=e;i++) cout<<a[i]<<' ';
	cout<<en;*/

    vector<ll>v;
    ll f=0;
    for(ll i=b+1;i<=e;i++){
        if(a[i]<a[i-1]){
            f++;
            //v.push_back(i);
        }
    }
    cout<<f<<en;
    /*for(auto i:v) cout<<i<<' ';
    cout<<en;*/
}


void REVERSE(ll l, ll r){
	ll in=0;
	for(ll i=l;i<=(l+r)/2;i++){
		swap(a[l+in],a[r-in]);
		in++;
	}
}

void CONQUER(Node x, Node y){
	ll temp[y.r-x.l+10];
	ll p1=x.l,p2=y.l,p3=0;
	while(p1<=x.r&&p2<=y.r){
		if(a[p1]<=a[p2]){
			p3++;temp[p3]=a[p1];p1++;
		}
		else{
			p3++;temp[p3]=a[p2];p2++;
		}
	}
	while(p1<=x.r){
		p3++;temp[p3]=a[p1];p1++;
	}
	while(p2<=y.r){
		p3++;temp[p3]=a[p2];p2++;
	}

	for(ll i=x.l;i<=y.r;i++){
		a[i]=temp[i-x.l+1];
	}

}

Node DEVIDE(ll b,ll e){
	if(b==e){
		Node x;
		x.l=r[b].l,x.r=r[b].r;
		return x;
	}
	ll mid=(b+e)/2;
	Node x,y;
	x=DEVIDE(b,mid);
	y=DEVIDE(mid+1,e);
	CONQUER(x,y);
	x.r=y.r;
	return x;
}



void NAZUMSORT(ll Begin,ll End){

    ll tot=0;
    ll length=10;
    ll koi=0;
    Node x;
    x.l=Begin,x.r=Begin;
    for(ll i=Begin+1;i<=End;i++){
        if(a[i]>=a[i-1]){
            x.r=i;
        }
        else{
            if(x.r-x.l+1>=length){
                ll last=koi;
                ll j;
                for(j=koi+length;j+length<x.l-1;j+=length){
                    NQUICK(last+1,j);
                    tot++;
                    Node xx;
                    xx.l=last+1,xx.r=j;
                    r[tot]=xx;
                    last=j;
                }
                if(last+1<=x.l-1){
                    NQUICK(last+1,x.l-1);
                    tot++;
                    Node xx;
                    xx.l=last+1,xx.r=x.l-1;
                    r[tot]=xx;
                }

                tot++;
                r[tot]=x;
                koi=x.r;

            }
            x.l=i,x.r=i;
        }
    }
    //cout<<en<<' '<<"THIS IS KOI "<<koi<<' '<<x.l<<' '<<x.r<<en;
    if(koi<End){
        ll last=koi;
        ll j;
        for(j=koi+length;j+length<x.l-1;j+=length){
            NQUICK(last+1,j);
            tot++;
            Node xx;
            xx.l=last+1,xx.r=j;
            r[tot]=xx;
            last=j;
        }
        if(last+1<=x.l-1){
            NQUICK(last+1,x.l-1);
            tot++;
            Node xx;
            xx.l=last+1,xx.r=x.l-1;
            r[tot]=xx;
        }
        tot++;
        r[tot]=x;
        koi=x.r;
    }


    //cout<<tot<<en;

    DEVIDE(1,tot);
    //cout<<"THIS IS TOT"<<tot<<en;

}

/*QUICK +Our algo   end*/



/*BUBBLE+Our algo start*/


ll a1[sz];
Node r1[sz];

void BUBBLE(ll low, ll high)
{
    ll i, j;
    ll c=0;
    for (i = low; i < high; i++){
        c++;
        for (j = low; j < high-c+1; j++)
            if (a1[j] > a1[j+1])
                swap(a1[j], a1[j+1]);
    }
}




void PRINT1(ll b,ll e){
    /*for(ll i=b;i<=e;i++) cout<<a[i]<<' ';
    cout<<en;*/

    vector<ll>v;
    ll f=0;
    for(ll i=b+1;i<=e;i++){
        if(a1[i]<a1[i-1]){
            f++;
            //v.push_back(i);
        }
    }
    cout<<f<<en;
    /*for(auto i:v) cout<<i<<' ';
    cout<<en;*/
}


void CONQUER1(Node x, Node y){
    ll temp[y.r-x.l+10];
    ll p1=x.l,p2=y.l,p3=0;
    while(p1<=x.r&&p2<=y.r){
        if(a1[p1]<=a1[p2]){
            p3++;temp[p3]=a1[p1];p1++;
        }
        else{
            p3++;temp[p3]=a1[p2];p2++;
        }
    }
    while(p1<=x.r){
        p3++;temp[p3]=a1[p1];p1++;
    }
    while(p2<=y.r){
        p3++;temp[p3]=a1[p2];p2++;
    }

    for(ll i=x.l;i<=y.r;i++){
        a1[i]=temp[i-x.l+1];
    }

}

Node DEVIDE1(ll b,ll e){
    if(b==e){
        Node x;
        x.l=r1[b].l,x.r=r1[b].r;
        return x;
    }
    ll mid=(b+e)/2;
    Node x,y;
    x=DEVIDE1(b,mid);
    y=DEVIDE1(mid+1,e);
    CONQUER1(x,y);
    x.r=y.r;
    return x;
}



void NAZUMSORT1(ll Begin,ll End){

    ll tot=0;
    ll length=10;
    ll koi=0;
    Node x;
    x.l=Begin,x.r=Begin;
    for(ll i=Begin+1;i<=End;i++){
        if(a1[i]>=a1[i-1]){
            x.r=i;
        }
        else{
            if(x.r-x.l+1>=length){
                ll last=koi;
                ll j;
                for(j=koi+length;j+length<x.l-1;j+=length){
                    BUBBLE(last+1,j);
                    tot++;
                    Node xx;
                    xx.l=last+1,xx.r=j;
                    r1[tot]=xx;
                    last=j;
                }
                if(last+1<=x.l-1){
                    BUBBLE(last+1,x.l-1);
                    tot++;
                    Node xx;
                    xx.l=last+1,xx.r=x.l-1;
                    r1[tot]=xx;
                }

                tot++;
                r1[tot]=x;
                koi=x.r;

            }
            x.l=i,x.r=i;
        }
    }
    //cout<<en<<' '<<"THIS IS KOI "<<koi<<' '<<x.l<<' '<<x.r<<en;
    if(koi<End){
        ll last=koi;
        ll j;
        for(j=koi+length;j+length<x.l-1;j+=length){
            BUBBLE(last+1,j);
            tot++;
            Node xx;
            xx.l=last+1,xx.r=j;
            r1[tot]=xx;
            last=j;
        }
        if(last+1<=x.l-1){
            BUBBLE(last+1,x.l-1);
            tot++;
            Node xx;
            xx.l=last+1,xx.r=x.l-1;
            r1[tot]=xx;
        }
        tot++;
        r1[tot]=x;
        koi=x.r;
    }


    //cout<<tot<<en;

    DEVIDE1(1,tot);
    //cout<<"THIS IS TOT"<<tot<<en;

}


/*BUBBLE+Our algo end */




/*MAHIMS IDEA start*/


ll a2[sz];
Node r2[sz];


ll NPARTITION2 (ll low, ll high)
{

    ll pivot = a2[high];
    //a[(low+high)/2];
    //swap(a[(low+high)/2],a[high]);
    ll i = (low - 1);

    for (ll j = low; j <= high - 1; j++)
    {
        if (a2[j] < pivot)
        {
            i++;
            swap(a2[i], a2[j]);
        }
    }
    swap(a2[i + 1],a2[high]);
    return (i + 1);
}

void NQUICK2(ll low, ll high)
{
    if (low < high)
    {

        ll pivot = NPARTITION2(low, high);
        NQUICK2(low, pivot - 1);
        NQUICK2(pivot + 1, high);
    }
}



void PRINT2(ll b,ll e){

    vector<ll>v;
    ll f=0;
    for(ll i=b+1;i<=e;i++){
        if(a2[i]<a2[i-1]){
            f++;
        }
    }
    cout<<f<<en;
}


void CONQUER2(Node x, Node y){
    ll temp[y.r-x.l+10];
    ll p1=x.l,p2=y.l,p3=0;
    while(p1<=x.r&&p2<=y.r){
        if(a2[p1]<=a2[p2]){
            p3++;temp[p3]=a2[p1];p1++;
        }
        else{
            p3++;temp[p3]=a2[p2];p2++;
        }
    }
    while(p1<=x.r){
        p3++;temp[p3]=a2[p1];p1++;
    }
    while(p2<=y.r){
        p3++;temp[p3]=a2[p2];p2++;
    }

    for(ll i=x.l;i<=y.r;i++){
        a2[i]=temp[i-x.l+1];
    }

}

Node DEVIDE2(ll b,ll e){
    if(b==e){
        Node x;
        x.l=r2[b].l,x.r=r2[b].r;
        return x;
    }
    ll mid=(b+e)/2;
    Node x,y;
    x=DEVIDE2(b,mid);
    y=DEVIDE2(mid+1,e);
    CONQUER2(x,y);
    x.r=y.r;
    return x;
}



void NAZUMSORT2(ll Begin,ll End){

    ll tot=0;
    ll length=10;
    ll koi=0;
    Node x;
    x.l=Begin,x.r=Begin;
    for(ll i=Begin+1;i<=End;i++){
        if(a2[i]>=a2[i-1]){
            x.r=i;
        }
        else{
            if(x.r-x.l+1>=length){
                ll last=koi;
                NQUICK2(koi+1,x.l-1);
                tot++;
                Node xx;
                xx.l=koi+1,xx.r=x.l-1;
                r2[tot]=xx;

            }
            x.l=i,x.r=i;
        }
    }
    //cout<<en<<' '<<"THIS IS KOI "<<koi<<' '<<x.l<<' '<<x.r<<en;
    if(koi<End){
        ll last=koi;
        NQUICK2(koi+1,x.l-1);
        tot++;
        Node xx;
        xx.l=koi+1,xx.r=x.l-1;
        r2[tot]=xx;
    }


    //cout<<tot<<en;

    DEVIDE2(1,tot);
    //cout<<"THIS IS TOT"<<tot<<en;

}


/*MAHIMS IDEA end*/






/*merge sort start*/


void merge(ll left, ll mid, ll right){
    ll i=0;
    ll ia=0,il=0,ir=0;
    ll size_left, size_right;

    size_left = mid - left + 1;
    size_right = right - mid;

    ll L[size_left], R[size_right];
    for(i = 0; i<size_left; i++){
        L[i] = mergenum[size_left];
    }

    for(i=0; i<size_left; i++){
        L[i] = mergenum[left+i];
    }

    for(i=0; i<size_right; i++){
        R[i] = mergenum[mid+1+i];
    }

    for(ia=left; il<size_left && ir<size_right;ia++){
        if(L[il] < R[ir]){
            mergenum[ia] = L[il];
            il += 1;
        }
        else{
            mergenum[ia] = R[ir];
            ir += 1;
        }
    }

    while(il < size_left){
        mergenum[ia] = L[il];
        il +=1;
        ia +=1;
    }

    while(ir < size_right){
        mergenum[ia] = R[ir];
        ir +=1;
        ia +=1;
    }

}

void margesort(ll left, ll right)
{
    if(left>=right)
    {
        return;
    }

    ll mid = left + (right-left)/2;
    margesort(left, mid);
    margesort(mid+1, right);
    merge(left, mid, right);

}


/*quick sort start*/
ll c;

ll partition (ll low, ll high)
{
    ll pivot = quicknum[high];
    //quicknum[(low+high)/2];
    //swap(quicknum[(low+high)/2],quicknum[high]);

    ll i = (low - 1);

    for (ll j = low; j <= high - 1; j++)
    {
        if (quicknum[j] < pivot)
        {
            i++;
            swap(quicknum[i], quicknum[j]);
        }
    }
    swap(quicknum[i + 1],quicknum[high]);
    return (i + 1);
}


void quickSort(ll low, ll high)
{
    if (low < high)
    {

        ll pivot = partition(low, high);
        quickSort(low, pivot - 1);
        quickSort(pivot + 1, high);
    }
    c++;
}
void printArray(ll size)
{
    ll i;
    for (i = 0; i < size; i++)
        cout << quicknum[i] << endl;
    cout << endl;
}

/*quick sort end*/

/*timsort start*/
ll timnum[sz];
const ll timSlice = 32;

void timInsertion(ll left, ll right)
{
    for (ll i = left + 1; i <= right; i++)
    {
        ll temp = timnum[i];
        ll j = i - 1;
        while (j >= left && timnum[j] > temp)
        {
            timnum[j+1] = timnum[j];
            j--;
        }
        timnum[j+1] = temp;
    }
}


void timMerge(ll l, ll m, ll r)
{

    ll len1 = m - l + 1, len2 = r - m;
    ll left[len1], right[len2];
    for (ll i = 0; i < len1; i++)
        left[i] = timnum[l + i];
    for (ll i = 0; i < len2; i++)
        right[i] = timnum[m + 1 + i];

    ll i = 0;
    ll j = 0;
    ll k = l;

    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            timnum[k] = left[i];
            i++;
        }
        else
        {
            timnum[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < len1)
    {
        timnum[k] = left[i];
        k++;
        i++;
    }

    while (j < len2)
    {
        timnum[k] = right[j];
        k++;
        j++;
    }
}

void timSort(ll n)
{
    for (ll i = 0; i < n; i+=timSlice)
        timInsertion(i, min((i+timSlice-1), (n-1)));

    for (ll size = timSlice; size < n; size = 2*size)
    {
        for (ll left = 0; left < n; left += 2*size)
        {
            ll mid = left + size - 1;
            ll right = min((left + 2*size - 1), (n-1));
              if(mid < right)
                timMerge(left, mid, right);
        }
    }
}

void printTimArray(ll n)
{
    for (ll i = 0; i < n; i++)
        cout << timnum[i] << endl;
    cout << endl;
}

/*timsort end*/

/*Radixsort*/

ll modd(ll a,ll b) {
   ll r = a / b;
   return (a - r*b);
}

void countsort(ll b,ll e,ll place)
{
        ll base=10;
        ll i;
        vector<ll>freq[base+10];
        ll yo=0;
        for(i=b;i<=e;i++){
            ll x=modd(radixnum[i]/place,base);
            freq[x].emplace_back(radixnum[i]);
        }

        ll in=b-1;

        for(ll i=0;i<=base-1;i++){
            for(ll j=0;j<freq[i].size();j++){
                in++;
                radixnum[in]=freq[i][j];
            }
        }
}
void RADIXSORT(ll b,ll e){
    ll maxx=0;
    for(ll i=b;i<=e;i++) maxx=max(maxx,radixnum[i]);

    ll mul=1;
    while(maxx){
        countsort(b,e,mul);
        mul*=10;
        maxx/=10;
    }
}

void RadixPRINT(ll b,ll e){
    /*for(ll i=b;i<=e;i++) cout<<a[i]<<' ';
    cout<<en;*/

    vector<ll>v;
    ll f=0;
    for(ll i=b+1;i<=e;i++){
        if(radixnum[i]<radixnum[i-1]){
            f++;
            //v.push_back(i);
        }
    }
    cout<<f<<en;
    /*for(auto i:v) cout<<i<<' ';
    cout<<en;*/
}


/*radixsort end*/




/*NS_MODIFIED_BY_NAZUM*/
ll a3[sz];
Node r3[sz];

void PRINT3(ll b,ll e){
    ll f=0;
    for(ll i=b+1;i<=e;i++){
        //cout<<a0[i]<<' ';
        if(a3[i]<a3[i-1]) f++;
    }
    cout<<f<<en;
}


void REVERSE3(ll l, ll r){
    ll in=0;
    ll xx=(l+r)/2;
    for(ll i=l;i<=xx;i++){
        swap(a3[l+in],a3[r-in]);
        in++;
    }
}


void AS_AS(Node x,Node y){
    ll temp[y.r-x.l+10];
    ll p1=x.l,p2=y.l,p3=0;
    while(p1<=x.r&&p2<=y.r){
        if(a3[p1]<=a3[p2]){
            p3++;temp[p3]=a3[p1];p1++;
        }
        else{
            p3++;temp[p3]=a3[p2];p2++;
        }
    }
    while(p1<=x.r){
        p3++;temp[p3]=a3[p1];p1++;
    }
    while(p2<=y.r){
        p3++;temp[p3]=a3[p2];p2++;
    }

    for(ll i=x.l;i<=y.r;i++){
        a3[i]=temp[i-x.l+1];
    }
}

void DES_DES(Node x,Node y){
    ll temp[y.r-x.l+10];
    ll p1=x.r,p2=y.r,p3=0;
    while(p1>=x.l&&p2>=y.l){
        if(a3[p1]<=a3[p2]){
            p3++;temp[p3]=a3[p1];p1--;
        }
        else{
            p3++;temp[p3]=a3[p2];p2--;
        }
    }
    while(p1>=x.l){
        p3++;temp[p3]=a3[p1];p1--;
    }
    while(p2>=y.l){
        p3++;temp[p3]=a3[p2];p2--;
    }

    for(ll i=x.l;i<=y.r;i++){
        a3[i]=temp[i-x.l+1];
    }

}

void AS_DES(Node x,Node y){
    ll temp[y.r-x.l+10];
    ll p1=x.l,p2=y.r,p3=0;
    while(p1<=x.r&&p2>=y.l){
        if(a3[p1]<=a3[p2]){
            p3++;temp[p3]=a3[p1];p1++;
        }
        else{
            p3++;temp[p3]=a3[p2];p2--;
        }
    }
    while(p1<=x.r){
        p3++;temp[p3]=a3[p1];p1++;
    }
    while(p2>=y.l){
        p3++;temp[p3]=a3[p2];p2--;
    }

    for(ll i=x.l;i<=y.r;i++){
        a3[i]=temp[i-x.l+1];
    }

}
void DES_AS(Node x,Node y){
    ll temp[y.r-x.l+10];
    ll p1=x.r,p2=y.l,p3=0;
    while(p1>=x.l&&p2<=y.r){
        if(a3[p1]<=a3[p2]){
            p3++;temp[p3]=a3[p1];p1--;
        }
        else{
            p3++;temp[p3]=a3[p2];p2++;
        }
    }
    while(p1>=x.l){
        p3++;temp[p3]=a3[p1];p1--;
    }
    while(p2<=y.r){
        p3++;temp[p3]=a3[p2];p2++;
    }

    for(ll i=x.l;i<=y.r;i++){
        a3[i]=temp[i-x.l+1];
    }
}

void CONQUER3(Node x, Node y){
    if(x.ty==1&&y.ty==1) AS_AS(x,y);
    else if(x.ty==0&&y.ty==0) DES_DES(x,y);
    else if(x.ty==1&&y.ty==0) AS_DES(x,y);
    else DES_AS(x,y);
}

Node DEVIDE3(ll b,ll e){
    if(b==e){
        Node x;
        x.l=r3[b].l,x.r=r3[b].r;
        x.ty=r3[b].ty;
        return x;
    }
    ll mid=(b+e)/2;
    Node x,y;
    x=DEVIDE3(b,mid);
    y=DEVIDE3(mid+1,e);
    CONQUER3(x,y);
    x.r=y.r;
    x.ty=1;
    return x;
}

void NAZUMSORT3(ll Begin,ll End){
    ll tot=0;
    Node x;
    x.l=Begin,x.r=Begin;
    x.ty=1;
    while(1){

        if(x.r+1>End) break;

        if(a3[x.r+1]>=a3[x.r]) x.ty=1;
        else x.ty=0;

        if(x.ty) while(x.r+1<=End&&a3[x.r+1]>=a3[x.r]) x.r++;
        else while(x.r+1<=End&&a3[x.r+1]<=a3[x.r]) x.r++;

        tot++;
        r3[tot]=x;

        x.l=x.r+1;
        x.r=x.r+1;
        x.ty=1;

    }

    if(x.l<=End&&x.r<=End){
        tot++;
        r3[tot]=x;
    }


    DEVIDE3(1,tot);
    //cout<<tot<<en;
    //cout<<r0[1].l<<' '<<r0[1].r<<en;

}

/*Natural merge updated start*/

ll t0[sz],natural0[sz];
ll ta0; //Number of markers obtained by linear scanning


 void Merge0(ll c[],ll d[],ll l,ll m,ll r);
 void MergePass0(ll x[],ll y[],ll s,ll n) ;
   //Declare the function first

void MergeSort0(ll aa[],ll n)
{
    ll *bb=new ll[n];
    ll s=1;
    while(s<ta0)
    {
                 MergePass0(aa,bb,s,n); //Merge into array b
                 s+=s; //The size of the two arrays doubled after merging
                 MergePass0(bb,aa,s,n); //Merge into array a, and ensure that the array elements in a are sorted
                 s+=s;
    }
}




void MergePass0(ll x[],ll y[],ll s,ll n)
{
    ll i=0;
    while(i<=ta0-2*s)
    {//Merge 2 adjacent sub-arrays of size s
        ll r=((i+2*s)<ta0)?t0[i+2*s]:n;

        Merge0(x,y,t0[i],t0[i+s]-1,r-1);
        i=i+2*s;
    }
    if(i+s<ta0) //The remaining elements are less than 2s, that is, s~2s
        Merge0(x,y,t0[i],t0[i+s]-1,n-1);
    else  if(i<ta0)
    {
        for(ll j=t0[i];j<=n-1;j++)
            y[j]=x[j];
    }
}





void Merge0(ll c[],ll d[],ll l,ll m,ll r)
{//Combine c[l:m] and c[m+1:r] to d[l:r]

    ll i=l,j=m+1,k=r;

    while((i<=m)&&(j<=r))
    {
        if(c[i]<=c[j])
            d[l++]=c[i++];  //d[l]=c[i],l++,i++
        else
            d[l++]=c[j++];
    }
    if(i>m)
                 for(ll q=j;q<=r;q++) //It means that all i is copied to d, just copy the remaining j to d, and the elements in c are in order at this time and can be copied directly
            d[l++]=c[q];
    else
                 for(ll p=i;p<=m;p++) //Denote that all j is copied to d, just copy the remaining i to d, and the elements in c are in order at this time, you can copy directly
            d[l++]=c[p];
}

void PrintArray0(ll aa[],ll n)
 {//Output the elements in the array
    for(ll i=0;i<n;i++)
        cout<<aa[i]<<" ";
    cout<<endl;
}


void GetBPoint0(ll aa[],ll bb[],ll n,ll &m)
 {//Number of markers obtained by natural merge sort linear scan
    ll j=0;
    bb[j++]=0;
    for(ll i=0;i<n-1;i++)
    {
        if(aa[i+1]<aa[i])
                         bb[j++]=i+1; //Record endpoint
    }
         m=j; //Record the number of endpoints
   // cout<<m<<en;
}


void PRINTN0(ll b,ll e){
    ll f=0;
    for(ll i=b+1;i<=e;i++){
        //cout<<a0[i]<<' ';
        if(natural0[i]<natural0[i-1]) f++;
    }
    cout<<f<<en;
}


/*Natural merge end*/


/*Natural merge updated*/

ll t[sz],tag[sz],natural[sz];
ll ta; 


 void Merge(ll c[],ll d[],ll l,ll m,ll r);
 void MergePass(ll x[],ll y[],ll s,ll n) ;
   

void MergeSort(ll aa[],ll nn)
{
    ll *bb=new ll[nn];
    ll s=1;
    while(s<=ta){
        MergePass(aa,bb,s,nn);
        s+=s;
        MergePass(bb,aa,s,nn);
        s+=s;
    }

    /*if(ta==0){
         //cout<<"Hair"<<en;
        if(tag[ta+1]==0){
            for(ll i=1;i<=nn/2;i++){
                swap(aa[i-1],aa[nn-i]);
            }
        }

        tag[ta+1]=1;
    }*/
}

void Merge(ll c[],ll d[],ll l,ll m,ll r,ll ltag,ll rtag)
 {
    //cout<<l<<' '<<m<<' '<<r<<' '<<ltag<<' '<<rtag<<' '<<en;
    if(ltag==1&&rtag==1){
        //as as
        ll i=l,j=m+1;

        while((i<=m)&&(j<=r)){
            if(c[i]<=c[j])
                d[l++]=c[i++];  
            else
                d[l++]=c[j++];
        }
        if(i>m)
            for(ll q=j;q<=r;q++) 
                d[l++]=c[q];
        else
            for(ll p=i;p<=m;p++) 
                d[l++]=c[p];
    }
    else if(ltag==1&&rtag==0){
                //as des
        ll i=l,j=r;

        while((i<=m)&&(j>=m+1)){
            if(c[i]<=c[j])
                d[l++]=c[i++];  
            else
                d[l++]=c[j--];
        }
        if(i>m)
            for(ll q=j;q>=m+1;q--) 
                d[l++]=c[q];
        else
            for(ll p=i;p<=m;p++) 
                d[l++]=c[p];

    }
    else if(ltag==0&&rtag==1){
        //des as

        ll i=m,j=m+1,k=l;
        while((i>=l)&&(j<=r)){
            if(c[i]<=c[j])
                d[k++]=c[i--];  
            else
                d[k++]=c[j++];
        }
        for(ll q=i;q>=l;q--) 
            d[k++]=c[q];
        for(ll p=j;p<=r;p++) 
            d[k++]=c[p];
    }
    else{
        //des des
        

        ll i=m,j=r,k=l;
        while((i>=l)&&(j>=m+1)){
            if(c[i]<=c[j])
                d[k++]=c[i--];  
            else
                d[k++]=c[j--];
        }
        for(ll q=i;q>=l;q--) 
            d[k++]=c[q];
        for(ll p=j;p>=m+1;p--) 
            d[k++]=c[p];
    }
}


void MergePass(ll x[],ll y[],ll s,ll n){

    /*cout<<"lv : "<<s<<" :";
    for(ll kk=0;kk<=15;kk++) cout<<*(x+kk)<<' ';
    cout<<en;*/



    ll i=0;
    while(i+2*s<=ta)
    {
        ll r=t[i+2*s];

        Merge(x,y,t[i],t[i+s]-1,r-1,tag[i+s],tag[i+2*s]);
        tag[i+s]=1,tag[i+2*s]=1;
        i=i+2*s;
    }


    if(i+s<=ta){

        Merge(x,y,t[i],t[i+s]-1,t[ta+1]-1,tag[i+s],tag[ta+1]);
        tag[i+s]=1,tag[ta+1]=1;
    }
    else{

        if(tag[ta+1]){
            for(ll j=t[i];j<=t[ta+1]-1;j++)
                y[j]=x[j];
        }
        else{
            ll in=t[i];
            for(ll j=t[ta+1]-1;j>=t[i];j--){
                y[in]=x[j];
                in++;
            }
        }
        tag[ta+1]=1;
    }

    /*if(s*2>=ta){
        cout<<"lv : "<<s*2<<" :";
        for(ll kk=0;kk<=15;kk++) cout<<*(y+kk)<<' ';
            cout<<en;
    }*/
    
}




void PrintArray(ll aa[],ll n)
 {
    for(ll i=0;i<n;i++)
        cout<<aa[i]<<" ";
    cout<<endl;
}


void GetBPoint(ll aa[],ll bb[],ll n,ll &m)
 {
    ll tot=0;
    ll End=n-1;
    ll xr=0;
    ll xty=1;
    while(1){

        if(xr+1>End) break;

        if(aa[xr+1]>=aa[xr]) xty=1;
        else xty=0;

        if(xty) while(xr+1<=End&&aa[xr+1]>=aa[xr]) xr++;
        else while(xr+1<=End&&aa[xr+1]<=aa[xr]) xr++;

        tot++;
        bb[tot]=xr+1;
        tag[tot]=xty;

        xr=xr+1;
        xty=1;

    }

    if(xr<=End){
        tot++;
        //r3[ta]=x;
        bb[tot]=xr+1;
        tag[tot]=xty;
    }
    m=tot-1;
    //cout<<t[ta+1]<<' '<<tag[ta+1]<<en;

    /*for(ll i=0;i<=4;i++){
        cout<<tag[i]<<' '<<t[i]<<en;
    }
    cout<<en;*/
    //cout<<ta<<en;
    
}

void PRINTN(ll b,ll e){
    ll f=0;
    for(ll i=b+1;i<=e;i++){
        /*if(i-b+1<=100){
            cout<<natural[i]<<' ';
            //if(natural[i]==1) f++;
        }*/
        if(natural[i]<natural[i-1]) f++;
    }
    cout<<en<<f<<en;
}


/*Natural merge updated end*/

/*DatasetGen Begin*/

ll data[5000006];

void Gen_data(ll n,ll len,ll per){
    srand(time(0));
    ll to=n/len;
    if(n%len) to++;
    ll des=(per*to)/100,asc=to-des;

    ll ini=rand()%mod,i=0;
    ll cnt=0,cnt1=0;
    while(cnt<des&&cnt1<asc){
        ll taken=cnt1+cnt;
        if(taken%2==1&&cnt<des){
            ini-=abs(rand())%mod;
            for(ll j=1;j<=len;j++){
                data[i]=ini;
                i++;
                ll val=abs(rand())%mod;
                if(j<len) ini-=val;
            }
            cnt++;
        }
        else if(taken%2==0&&cnt1<asc){
            ini+=abs(rand())%mod;
            for(ll j=1;j<=len;j++){
                data[i]=ini;
                i++;
                ll val=abs(rand())%mod;
                if(j<len) ini+=val;
            }
            cnt1++;
        }
    }

    while(cnt<des){
        ini+=abs(rand())%mod;
        for(ll j=1;j<=len;j++){
                data[i]=ini;
                i++;
                ll val=abs(rand())%mod;
                if(j<len) ini-=val;
        }
        cnt++;
    }
    while(cnt1<asc){
        ini-=abs(rand())%mod;
        for(ll j=1;j<=len;j++){
                data[i]=ini;
                i++;
                ll val=abs(rand())%mod;
                if(j<len) ini+=val;
            }
        cnt1++;
    }

}

void print(ll n){
    for(ll i=0;i<n;i++) cout<<data[i]<<' ';
    cout<<en;
}

/*datset gen end*/


int main(){
    _fastio
    srand(time(NULL));
    ll x;

    ll c=0;
    n=1000000;

for(ll per=0;per<=100;per+=5){
    Gen_data(n,2,per);

    cout<<"For :"<<per<<"% ,result is: "<<en;
    

    for(ll i=1;i<=n;i++)
    {
    	//x = rand();
        /*if(i%2) x=1e18-i;
        else{
            x=c;
            c++;
        }*/
       /* x=i%5;
        if(x==0) x=5;
        x=6-x;*/
        //x=n-i;
        x=data[i-1];
        anazumm[i-1] = x;
    	quicknum[i] = x;
    	mergenum[i] = x;
    	stlnum[i] = x;
        timnum[i]=x;
        radixnum[i]=x;
        a0[i]=x;
        a[i]=x;
        a1[i]=x;
        a2[i]=x;
        a3[i]=x;
        natural0[i-1]=x;
        natural[i-1]=x;

    	// cout << a[i] << endl;

    }
    /*vector<ll>v={5,4,3,2,1,1,2,3,4,5,1,2,3,4,5,4};
    for(ll i=0;i<=15;i++) natural[i]=v[i];*/


    /*radix sorting array checking:
    printRadixnumArray(n); */
   /* auto start_RadixSort = high_resolution_clock::now();
    RADIXSORT(1,n);
    auto stop_RadixSort = high_resolution_clock::now();
    //RadixPRINT(1,n);
    after sorting sorted array checking:
    printRadixnumArray(n); 
    auto duration_RadixSort = duration_cast<microseconds>(stop_RadixSort - start_RadixSort);

    cout << "Required time of RadixSort: " ;
    cout << duration_RadixSort.count() << " micro-sec." << endl;
    cout << endl;*/




	/*quick sort time calculating*/
	/*auto start_Quicksort = high_resolution_clock::now();
	quickSort(1, n);
	auto stop_Quicksort = high_resolution_clock::now();
	auto duration_Quicksort = duration_cast<microseconds>(stop_Quicksort - start_Quicksort);

	cout << "Required time of Quicksort: " ;
    cout << duration_Quicksort.count() << " micro-sec." << endl;
    cout << endl;
*/


    /*merge sort time calculating*/
	auto start_Mergesort = high_resolution_clock::now();
	margesort(1,n);
	auto stop_Mergesort = high_resolution_clock::now();
	auto duration_Mergesort = duration_cast<microseconds>(stop_Mergesort - start_Mergesort);

	cout << "Required time of Mergesort: " ;
    cout << duration_Mergesort.count() << " micro-sec." << endl;
    cout << endl;

     /*STL sort time calculating*/
    //int lmt = sizeof(stlnum) / sizeof(stlnum[0]);
    auto start_STLSORT = high_resolution_clock::now();
    sort(stlnum+1, stlnum + n+1);
    auto stop_STLSORT = high_resolution_clock::now();
    auto duration_STLSORT = duration_cast<microseconds>(stop_STLSORT - start_STLSORT);

    cout << "Required time of Introsort: " ;
    cout << duration_STLSORT.count() << " micro-sec." << endl;
    cout << endl;


    /*tim sorting array checking:
    printTimArray(n); */
    auto start_TimSort = high_resolution_clock::now();
    timSort(n);
    auto stop_TimSort = high_resolution_clock::now();
    //after sorting sorted array checking:
   // printTimArray(n); 
    auto duration_TimSort = duration_cast<microseconds>(stop_TimSort - start_TimSort);

    cout << "Required time of TimSort: " ;
    cout << duration_TimSort.count() << " micro-sec." << endl;
    cout << endl;

    /*Quick+nazum sort time calculating*/
   /* auto start_NAZUMSORT0 = high_resolution_clock::now();
    NAZUMSORT0(1,n);
    //PRINT0(1,n);
    auto stop_NAZUMSORT0 = high_resolution_clock::now();
    auto duration_NAZUMSORT0 = duration_cast<microseconds>(stop_NAZUMSORT0 - start_NAZUMSORT0);

    cout << "Required time of NS: " ;
    cout << duration_NAZUMSORT0.count() << " micro-sec." << endl;
    cout << endl;*/


    /*Quick+nazum sort time calculating*/
    /*auto start_NAZUMSORT = high_resolution_clock::now();
    //PRINT(1,10);
    NAZUMSORT(1,n);
    //NQUICK(1,n);
    //PRINT(1,n);
    auto stop_NAZUMSORT = high_resolution_clock::now();
    auto duration_NAZUMSORT = duration_cast<microseconds>(stop_NAZUMSORT - start_NAZUMSORT);

    cout << "Required time of QUICK+NS: " ;
    cout << duration_NAZUMSORT.count() << " micro-sec." << endl;
    cout << endl;
*/

    /*BUBBLE+our algo time calculating*/
    /*auto start_NAZUMSORT1 = high_resolution_clock::now();
    //PRINT1(1,10);
    NAZUMSORT1(1,n);
    //PRINT1(1,n);
    auto stop_NAZUMSORT1 = high_resolution_clock::now();
    auto duration_NAZUMSORT1 = duration_cast<microseconds>(stop_NAZUMSORT1 - start_NAZUMSORT1);

    cout << "Required time of BUBBLE+NS: " ;
    cout << duration_NAZUMSORT1.count() << " micro-sec." << endl;
    cout << endl;*/


    /*Mahims Idea time calculating*/
   /* auto start_NAZUMSORT2 = high_resolution_clock::now();
    NAZUMSORT2(1,n);
    //PRINT2(1,n);
    auto stop_NAZUMSORT2 = high_resolution_clock::now();
    auto duration_NAZUMSORT2 = duration_cast<microseconds>(stop_NAZUMSORT2 - start_NAZUMSORT2);

    cout << "Required time of MAHIMS_IDEA: " ;
    cout << duration_NAZUMSORT2.count() << " micro-sec." << endl;
    cout << endl;
*/


    /*NS_MODIFIED_BY_MAHIM*/
   /* auto start_NAZUMSORTMO = high_resolution_clock::now();
    nazum_sort_modified();
    auto stop_NAZUMSORTMO = high_resolution_clock::now();
    auto duration_NAZUMSORTMO = duration_cast<microseconds>(stop_NAZUMSORTMO - start_NAZUMSORTMO);
    //PRINT4(0,n-1);
    cout << "Required time of Nazum_Sort_MODIFIED_BY_MAHIM: " ;
    cout << duration_NAZUMSORTMO.count() << " micro-sec." << endl;
    cout << endl;*/


    /*NS_MODIFIED_BY_NAZUM*/
   /* auto start_NAZUMSORTM3 = high_resolution_clock::now();
    NAZUMSORT3(1,n);
    auto stop_NAZUMSORTM3 = high_resolution_clock::now();
    auto duration_NAZUMSORTM3 = duration_cast<microseconds>(stop_NAZUMSORTM3 - start_NAZUMSORTM3);
    //PRINT3(1,n);

    cout << "Required time of Nazum_Sort_MODIFIED_BY_NAZUM: " ;
    cout << duration_NAZUMSORTM3.count() << "micro-sec." << endl;
    cout << endl;*/


    /*Natural start*/
    auto start_NAZUMSORTM4 = high_resolution_clock::now();


    // for(ll i=0;i<20;i++) cout<<natural[i]<<' ';
    //     cout<<en;

    GetBPoint0(natural0,t0,n,ta0);
    MergeSort0(natural0,n);

    auto stop_NAZUMSORTM4 = high_resolution_clock::now();
    auto duration_NAZUMSORTM4 = duration_cast<microseconds>(stop_NAZUMSORTM4 - start_NAZUMSORTM4);

    //PRINTN0(0,n-1);

    cout << "Required time of Natural merge:  " ;
    cout << duration_NAZUMSORTM4.count() << " micro-sec." << endl;
    cout << endl;

    // for(ll i=0;i<20;i++) cout<<natural[i]<<' ';
    //     cout<<en;

    /*Natural merge updated */
    auto start_NAZUMSORTM5 = high_resolution_clock::now();

    GetBPoint(natural,t,n,ta);
    MergeSort(natural,n);

    auto stop_NAZUMSORTM5 = high_resolution_clock::now();
    auto duration_NAZUMSORTM5 = duration_cast<microseconds>(stop_NAZUMSORTM5 - start_NAZUMSORTM5);

    //PRINTN(0,n-1);

    cout << "Required time of Natural merge updated:  " ;
    cout << duration_NAZUMSORTM5.count() << " micro-sec." << endl;
    cout << endl;
    /*Natural merge updated*/
}



    return 0;
}


void PRINT4(ll b,ll e){
    ll f=0;
    for(ll i=b+1;i<=e;i++){
        if(anazumm[i]<anazumm[i-1]) f++;
    }
    cout<<f<<en;
}




void nazum_sort_modified()
{
    ll i,j,p,l1,h1,l2,h2,k=0;
    char ch1,ch2;

    i = 0;
    while(i<=n-1)
    {
        if(anazumm[i]<=anazumm[i+1] && i+1<=n-1)
        {
            l2 = i;
            h2 = i;

            while(anazumm[i]<=anazumm[i+1] && i+1<=n-1)
            {
                i++;
                h2++;
            }
            lista[k] = l2;
            listb[k] = h2;
            listch[k] = 'a';
            k++;
            i++;
        }

        else if(anazumm[i]>=anazumm[i+1] && i+1<=n-1)
        {
            l2 = i;
            h2 = i;

            while(anazumm[i]>=anazumm[i+1] && i+1<=n-1)
            {
                i++;
                h2++;
            }
            //for(j=l2,p=h2;j<=(h2+l2)/2;j++,p--)
                //swap(a[j],a[p]);

            lista[k] = l2;
            listb[k] = h2;
            listch[k] = 'd';

            k++;
            i++;
        }
        else
        {
            if(i<=n-1)
            {
                l2 = i;
                h2 = i;
                lista[k] = l2;
                listb[k] = h2;
                listch[k] = 'a';
                k++;
                i++;
            }
        }
    }

    merge_sort(k);


}

void merge_sort(ll k)
{
    ll size,low1,up1,low2,up2;
    size = 1;
    while(size<k)
    {
        low1 = 0;
        while(low1+size<k)
        {
            up1 = low1 + size - 1;
            low2 = low1 + size;
            up2 = low2 + size - 1;
            if(up2>=k)
                up2 = k - 1;
            nazum_merge(low1,up1,low2,up2);
            low1 = up2 + 1;
        }
        size = size * 2;
    }
}



void nazum_merge(ll low1,ll up1,ll low2,ll up2)
{
    ll i,j,k,l1,l2,h1,h2;
    ll l,mid,h;
    l = low1;
    mid = up1;
    h = up2;
    if(l==mid && mid+1==h)
    {
        if(listch[l]=='a'&&listch[h]=='a')
        {
            l1 = lista[l];
            h1 = listb[mid];
            l2 = lista[mid+1];
            h2 = listb[h];
            i = l1;
            j = l2;
            k = l1;

            while(i<=h1 && j<=h2)
            {
                if(anazumm[i]<anazumm[j])
                {
                    bnazumm[k] = anazumm[i];
                    i++;
                    k++;
                }
                else
                {
                    bnazumm[k] = anazumm[j];
                    j++;
                    k++;
                }
            }
            while(i<=h1)
            {
                bnazumm[k] = anazumm[i];
                i++;
                k++;
            }
            while(j<=h2)
            {
                bnazumm[k] = anazumm[j];
                j++;
                k++;
            }
        }

        else if(listch[l]=='a'&&listch[h]=='d')
        {
            l1 = lista[l];
            h1 = listb[mid];
            l2 = lista[mid+1];
            h2 = listb[h];
            i = l1;
            j = h2;
            k = l1;

            while(i<=h1 && j>=l2)
            {
                if(anazumm[i]<anazumm[j])
                {
                    bnazumm[k] = anazumm[i];
                    i++;
                    k++;
                }
                else
                {
                    bnazumm[k] = anazumm[j];
                    j--;
                    k++;
                }
            }
            while(i<=h1)
            {
                bnazumm[k] = anazumm[i];
                i++;
                k++;
            }
            while(j>=l2)
            {
                bnazumm[k] = anazumm[j];
                j--;
                k++;
            }
        }

        else if(listch[l]=='d'&&listch[h]=='a')
        {
            l1 = lista[l];
            h1 = listb[mid];
            l2 = lista[mid+1];
            h2 = listb[h];
            i = h1;
            j = l2;
            k = l1;

            while(i>=l1 && j<=h2)
            {
                if(anazumm[i]<anazumm[j])
                {
                    bnazumm[k] = anazumm[i];
                    i--;
                    k++;
                }
                else
                {
                    bnazumm[k] = anazumm[j];
                    j++;
                    k++;
                }
            }
            while(i>=l1)
            {
                bnazumm[k] = anazumm[i];
                i--;
                k++;
            }
            while(j<=h2)
            {
                bnazumm[k] = anazumm[j];
                j++;
                k++;
            }
        }

        else if(listch[l]=='d'&&listch[h]=='d')
        {
            l1 = lista[l];
            h1 = listb[mid];
            l2 = lista[mid+1];
            h2 = listb[h];
            i = h1;
            j = h2;
            k = l1;

            while(i>=l1 && j>=l2)
            {
                if(anazumm[i]<anazumm[j])
                {
                    bnazumm[k] = anazumm[i];
                    i--;
                    k++;
                }
                else
                {
                    bnazumm[k] = anazumm[j];
                    j--;
                    k++;
                }
            }
            while(i>=l1)
            {
                bnazumm[k] = anazumm[i];
                i--;
                k++;
            }
            while(j>=l2)
            {
                bnazumm[k] = anazumm[j];
                j--;
                k++;
            }
        }
    }


    else if(l!=mid && mid+1==h)
    {
        if(listch[h]=='a')
        {
            l1 = lista[l];
            h1 = listb[mid];
            l2 = lista[mid+1];
            h2 = listb[h];
            i = l1;
            j = l2;
            k = l1;

            while(i<=h1 && j<=h2)
            {
                if(anazumm[i]<anazumm[j])
                {
                    bnazumm[k] = anazumm[i];
                    i++;
                    k++;
                }
                else
                {
                    bnazumm[k] = anazumm[j];
                    j++;
                    k++;
                }
            }
            while(i<=h1)
            {
                bnazumm[k] = anazumm[i];
                i++;
                k++;
            }
            while(j<=h2)
            {
                bnazumm[k] = anazumm[j];
                j++;
                k++;
            }
        }

        else if(listch[h]=='d')
        {
            l1 = lista[l];
            h1 = listb[mid];
            l2 = lista[mid+1];
            h2 = listb[h];
            i = l1;
            j = h2;
            k = l1;

            while(i<=h1 && j>=l2)
            {
                if(anazumm[i]<anazumm[j])
                {
                    bnazumm[k] = anazumm[i];
                    i++;
                    k++;
                }
                else
                {
                    bnazumm[k] = anazumm[j];
                    j--;
                    k++;
                }
            }
            while(i<=h1)
            {
                bnazumm[k] = anazumm[i];
                i++;
                k++;
            }
            while(j>=l2)
            {
                bnazumm[k] = anazumm[j];
                j--;
                k++;
            }
        }
    }

    else if(l==mid && mid+1!=h)
    {
        if(listch[l]=='a')
        {
            l1 = lista[l];
            h1 = listb[mid];
            l2 = lista[mid+1];
            h2 = listb[h];
            i = l1;
            j = l2;
            k = l1;

            while(i<=h1 && j<=h2)
            {
                if(anazumm[i]<anazumm[j])
                {
                    bnazumm[k] = anazumm[i];
                    i++;
                    k++;
                }
                else
                {
                    bnazumm[k] = anazumm[j];
                    j++;
                    k++;
                }
            }
            while(i<=h1)
            {
                bnazumm[k] = anazumm[i];
                i++;
                k++;
            }
            while(j<=h2)
            {
                bnazumm[k] = anazumm[j];
                j++;
                k++;
            }
        }

        else if(listch[l]=='d')
        {
            l1 = lista[l];
            h1 = listb[mid];
            l2 = lista[mid+1];
            h2 = listb[h];
            i = h1;
            j = l2;
            k = l1;

            while(i>=l1 && j<=h2)
            {
                if(anazumm[i]<anazumm[j])
                {
                    bnazumm[k] = anazumm[i];
                    i--;
                    k++;
                }
                else
                {
                    bnazumm[k] = anazumm[j];
                    j++;
                    k++;
                }
            }
            while(i>=l1)
            {
                bnazumm[k] = anazumm[i];
                i--;
                k++;
            }
            while(j<=h2)
            {
                bnazumm[k] = anazumm[j];
                j++;
                k++;
            }
        }
    }

    else if(l!=mid && mid+1!=h)
    {
        l1 = lista[l];
        h1 = listb[mid];
        l2 = lista[mid+1];
        h2 = listb[h];
        i = l1;
        j = l2;
        k = l1;
        while(i<=h1 && j<=h2)
        {
            if(anazumm[i]<anazumm[j])
            {
                bnazumm[k] = anazumm[i];
                i++;
                k++;
            }
            else
            {
                bnazumm[k] = anazumm[j];
                j++;
                k++;
            }
        }
        while(i<=h1)
        {
            bnazumm[k] = anazumm[i];
            i++;
            k++;
        }
        while(j<=h2)
        {
            bnazumm[k] = anazumm[j];
            j++;
            k++;
        }
    }

    for(k=lista[l];k<=listb[h];k++)
        anazumm[k] = bnazumm[k];
}





