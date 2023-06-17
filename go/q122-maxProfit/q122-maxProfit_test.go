package q122_maxprofit

import (
	"testing"
)

func Test_maxProfit(t *testing.T) {
	type args struct {
		prices []int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			args: args{prices: []int{7, 1, 5, 3, 6, 4}},
			want: 7,
		},
		{
			args: args{prices: []int{1, 2, 3, 4, 5}},
			want: 4,
		},
		{
			args: args{prices: []int{7, 6, 4, 3, 1}},
			want: 0,
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := maxProfit(tt.args.prices); got != tt.want {
				t.Errorf("maxProfit() = %v, want %v", got, tt.want)
			}
		})
	}
}

func Test_maxProfit_2(t *testing.T) {
	type args struct {
		prices []int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			args: args{prices: []int{7, 1, 5, 3, 6, 4}},
			want: 7,
		},
		{
			args: args{prices: []int{1, 2, 3, 4, 5}},
			want: 4,
		},
		{
			args: args{prices: []int{7, 6, 4, 3, 1}},
			want: 0,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := maxProfit_2(tt.args.prices); got != tt.want {
				t.Errorf("maxProfit_2() = %v, want %v", got, tt.want)
			}
		})
	}
}

func Test_maxProfit_3(t *testing.T) {
	type args struct {
		prices []int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			args: args{prices: []int{7, 1, 5, 3, 6, 4}},
			want: 7,
		},
		{
			args: args{prices: []int{1, 2, 3, 4, 5}},
			want: 4,
		},
		{
			args: args{prices: []int{7, 6, 4, 3, 1}},
			want: 0,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := maxProfit_3(tt.args.prices); got != tt.want {
				t.Errorf("maxProfit_3() = %v, want %v", got, tt.want)
			}
		})
	}
}

func Benchmark_maxProfit(t *testing.B) {
	for i := 0; i < t.N; i++ {
		maxProfit([]int{7, 1, 5, 3, 6, 4})
	}
}

func Benchmark_maxProfit_2(t *testing.B) {
	for i := 0; i < t.N; i++ {
		maxProfit_2([]int{7, 1, 5, 3, 6, 4})
	}
}

func Benchmark_maxProfit_3(t *testing.B) {
	for i := 0; i < t.N; i++ {
		maxProfit_3([]int{7, 1, 5, 3, 6, 4})
	}
}