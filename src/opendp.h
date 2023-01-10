#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/**
 * A struct that can wrap any object.
 */
typedef struct AnyObject AnyObject;

typedef struct FfiError {
  char *variant;
  char *message;
  char *backtrace;
} FfiError;

enum FfiResult_____AnyObject_Tag {
  Ok_____AnyObject,
  Err_____AnyObject,
};
typedef uint32_t FfiResult_____AnyObject_Tag;

typedef struct FfiResult_____AnyObject {
  FfiResult_____AnyObject_Tag tag;
  union {
    struct {
      struct AnyObject *ok;
    };
    struct {
      struct FfiError *err;
    };
  };
} FfiResult_____AnyObject;

typedef uint8_t c_bool;

enum FfiResult_____c_bool_Tag {
  Ok_____c_bool,
  Err_____c_bool,
};
typedef uint32_t FfiResult_____c_bool_Tag;

typedef struct FfiResult_____c_bool {
  FfiResult_____c_bool_Tag tag;
  union {
    struct {
      c_bool *ok;
    };
    struct {
      struct FfiError *err;
    };
  };
} FfiResult_____c_bool;

enum FfiResult_____c_void_Tag {
  Ok_____c_void,
  Err_____c_void,
};
typedef uint32_t FfiResult_____c_void_Tag;

typedef struct FfiResult_____c_void {
  FfiResult_____c_void_Tag tag;
  union {
    struct {
      void *ok;
    };
    struct {
      struct FfiError *err;
    };
  };
} FfiResult_____c_void;

enum FfiResult_____c_char_Tag {
  Ok_____c_char,
  Err_____c_char,
};
typedef uint32_t FfiResult_____c_char_Tag;

typedef struct FfiResult_____c_char {
  FfiResult_____c_char_Tag tag;
  union {
    struct {
      char *ok;
    };
    struct {
      struct FfiError *err;
    };
  };
} FfiResult_____c_char;

typedef struct FfiSlice {
  const void *ptr;
  uintptr_t len;
} FfiSlice;

enum FfiResult_____FfiSlice_Tag {
  Ok_____FfiSlice,
  Err_____FfiSlice,
};
typedef uint32_t FfiResult_____FfiSlice_Tag;

typedef struct FfiResult_____FfiSlice {
  FfiResult_____FfiSlice_Tag tag;
  union {
    struct {
      struct FfiSlice *ok;
    };
    struct {
      struct FfiError *err;
    };
  };
} FfiResult_____FfiSlice;

enum FfiResult_____AnyMeasurement_Tag {
  Ok_____AnyMeasurement,
  Err_____AnyMeasurement,
};
typedef uint32_t FfiResult_____AnyMeasurement_Tag;

typedef struct FfiResult_____AnyMeasurement {
  FfiResult_____AnyMeasurement_Tag tag;
  union {
    struct {
      AnyMeasurement *ok;
    };
    struct {
      struct FfiError *err;
    };
  };
} FfiResult_____AnyMeasurement;

enum FfiResult_____AnyTransformation_Tag {
  Ok_____AnyTransformation,
  Err_____AnyTransformation,
};
typedef uint32_t FfiResult_____AnyTransformation_Tag;

typedef struct FfiResult_____AnyTransformation {
  FfiResult_____AnyTransformation_Tag tag;
  union {
    struct {
      AnyTransformation *ok;
    };
    struct {
      struct FfiError *err;
    };
  };
} FfiResult_____AnyTransformation;

bool opendp_core___error_free(struct FfiError *this_);

struct FfiResult_____AnyObject opendp_core__transformation_map(const AnyTransformation *transformation,
                                                               const struct AnyObject *distance_in);

struct FfiResult_____c_bool opendp_core__transformation_check(const AnyTransformation *transformation,
                                                              const struct AnyObject *distance_in,
                                                              const struct AnyObject *distance_out);

struct FfiResult_____AnyObject opendp_core__measurement_map(const AnyMeasurement *measurement,
                                                            const struct AnyObject *distance_in);

struct FfiResult_____c_bool opendp_core__measurement_check(const AnyMeasurement *measurement,
                                                           const struct AnyObject *distance_in,
                                                           const struct AnyObject *distance_out);

struct FfiResult_____AnyObject opendp_core__measurement_invoke(const AnyMeasurement *this_,
                                                               const struct AnyObject *arg);

struct FfiResult_____c_void opendp_core___measurement_free(AnyMeasurement *this_);

struct FfiResult_____AnyObject opendp_core__transformation_invoke(const AnyTransformation *this_,
                                                                  const struct AnyObject *arg);

struct FfiResult_____c_void opendp_core___transformation_free(AnyTransformation *this_);

struct FfiResult_____c_char opendp_core__transformation_input_carrier_type(AnyTransformation *this_);

struct FfiResult_____c_char opendp_core__measurement_input_carrier_type(AnyMeasurement *this_);

struct FfiResult_____c_char opendp_core__transformation_input_distance_type(AnyTransformation *this_);

struct FfiResult_____c_char opendp_core__transformation_output_distance_type(AnyTransformation *this_);

struct FfiResult_____c_char opendp_core__measurement_input_distance_type(AnyMeasurement *this_);

struct FfiResult_____c_char opendp_core__measurement_output_distance_type(AnyMeasurement *this_);

struct FfiResult_____AnyObject opendp_data__slice_as_object(const struct FfiSlice *raw,
                                                            const char *T);

struct FfiResult_____c_char opendp_data__object_type(struct AnyObject *this_);

struct FfiResult_____FfiSlice opendp_data__object_as_slice(const struct AnyObject *obj);

struct FfiResult_____FfiSlice opendp_data__ffislice_of_anyobjectptrs(const struct FfiSlice *raw);

struct FfiResult_____c_void opendp_data__object_free(struct AnyObject *this_);

/**
 * Frees the slice, but not what the slice references!
 */
struct FfiResult_____c_void opendp_data__slice_free(struct FfiSlice *this_);

struct FfiResult_____c_void opendp_data__str_free(char *this_);

struct FfiResult_____c_void opendp_data__bool_free(c_bool *this_);

struct FfiResult_____AnyObject opendp_data__smd_curve_epsilon(const struct AnyObject *curve,
                                                              const struct AnyObject *delta);

struct FfiResult_____c_char opendp_data__to_string(const struct AnyObject *this_);

struct FfiResult_____AnyMeasurement opendp_meas__make_base_laplace(const void *scale,
                                                                   const char *D);

struct FfiResult_____AnyMeasurement opendp_meas__make_base_gaussian(const void *scale,
                                                                    const char *D,
                                                                    const char *MO);

struct FfiResult_____AnyMeasurement opendp_meas__make_base_analytic_gaussian(double scale,
                                                                             const char *D);

struct FfiResult_____AnyMeasurement opendp_meas__make_base_geometric(const void *scale,
                                                                     const struct AnyObject *bounds,
                                                                     const char *D,
                                                                     const char *QO);

struct FfiResult_____AnyMeasurement opendp_meas__make_base_ptr(const void *scale,
                                                               const void *threshold,
                                                               const char *TK,
                                                               const char *TV);

struct FfiResult_____AnyMeasurement opendp_meas__make_randomized_response_bool(const void *prob,
                                                                               c_bool constant_time,
                                                                               const char *Q);

struct FfiResult_____AnyMeasurement opendp_meas__make_randomized_response(const struct AnyObject *categories,
                                                                          const void *prob,
                                                                          c_bool constant_time,
                                                                          const char *T,
                                                                          const char *Q);

struct FfiResult_____AnyTransformation opendp_trans__make_sized_bounded_covariance(unsigned int size,
                                                                                   const struct AnyObject *bounds_0,
                                                                                   const struct AnyObject *bounds_1,
                                                                                   unsigned int ddof,
                                                                                   const char *S);

struct FfiResult_____AnyTransformation opendp_trans__make_split_lines(void);

struct FfiResult_____AnyTransformation opendp_trans__make_split_records(const char *separator);

struct FfiResult_____AnyTransformation opendp_trans__make_create_dataframe(const struct AnyObject *col_names,
                                                                           const char *K);

struct FfiResult_____AnyTransformation opendp_trans__make_split_dataframe(const char *separator,
                                                                          const struct AnyObject *col_names,
                                                                          const char *K);

struct FfiResult_____AnyTransformation opendp_trans__make_select_column(const struct AnyObject *key,
                                                                        const char *K,
                                                                        const char *TOA);

struct FfiResult_____AnyTransformation opendp_trans__make_identity(const char *D, const char *M);

struct FfiResult_____AnyTransformation opendp_trans__make_is_equal(const struct AnyObject *value,
                                                                   const char *TIA);

struct FfiResult_____AnyTransformation opendp_trans__make_is_null(const char *DIA);

struct FfiResult_____AnyTransformation opendp_trans__make_bounded_sum(const struct AnyObject *bounds,
                                                                      const char *MI,
                                                                      const char *T);

struct FfiResult_____AnyTransformation opendp_trans__make_sized_bounded_sum(unsigned int size,
                                                                            const struct AnyObject *bounds,
                                                                            const char *MI,
                                                                            const char *T);

struct FfiResult_____AnyTransformation opendp_trans__make_sized_bounded_int_checked_sum(unsigned int size,
                                                                                        const struct AnyObject *bounds,
                                                                                        const char *T);

struct FfiResult_____AnyTransformation opendp_trans__make_bounded_int_monotonic_sum(const struct AnyObject *bounds,
                                                                                    const char *T);

struct FfiResult_____AnyTransformation opendp_trans__make_sized_bounded_int_monotonic_sum(unsigned int size,
                                                                                          const struct AnyObject *bounds,
                                                                                          const char *T);

struct FfiResult_____AnyTransformation opendp_trans__make_bounded_int_ordered_sum(const struct AnyObject *bounds,
                                                                                  const char *T);

struct FfiResult_____AnyTransformation opendp_trans__make_sized_bounded_int_ordered_sum(unsigned int size,
                                                                                        const struct AnyObject *bounds,
                                                                                        const char *T);

struct FfiResult_____AnyTransformation opendp_trans__make_bounded_int_split_sum(const struct AnyObject *bounds,
                                                                                const char *T);

struct FfiResult_____AnyTransformation opendp_trans__make_sized_bounded_int_split_sum(unsigned int size,
                                                                                      const struct AnyObject *bounds,
                                                                                      const char *T);

struct FfiResult_____AnyTransformation opendp_trans__make_bounded_float_checked_sum(unsigned int size_limit,
                                                                                    const struct AnyObject *bounds,
                                                                                    const char *S);

struct FfiResult_____AnyTransformation opendp_trans__make_sized_bounded_float_checked_sum(unsigned int size,
                                                                                          const struct AnyObject *bounds,
                                                                                          const char *S);

struct FfiResult_____AnyTransformation opendp_trans__make_bounded_float_ordered_sum(unsigned int size_limit,
                                                                                    const struct AnyObject *bounds,
                                                                                    const char *S);

struct FfiResult_____AnyTransformation opendp_trans__make_sized_bounded_float_ordered_sum(unsigned int size,
                                                                                          const struct AnyObject *bounds,
                                                                                          const char *S);

struct FfiResult_____AnyTransformation opendp_trans__make_sized_bounded_sum_of_squared_deviations(unsigned int size_limit,
                                                                                                  const struct AnyObject *bounds,
                                                                                                  const char *S);

struct FfiResult_____AnyTransformation opendp_trans__make_count(const char *TIA, const char *TO);

struct FfiResult_____AnyTransformation opendp_trans__make_count_distinct(const char *TIA,
                                                                         const char *TO);

struct FfiResult_____AnyTransformation opendp_trans__make_count_by_categories(const struct AnyObject *categories,
                                                                              const char *MO,
                                                                              const char *TI,
                                                                              const char *TO);

struct FfiResult_____AnyTransformation opendp_trans__make_count_by(const char *MO,
                                                                   const char *TK,
                                                                   const char *TV);

struct FfiResult_____AnyTransformation opendp_trans__make_sized_bounded_mean(unsigned int size,
                                                                             const struct AnyObject *bounds,
                                                                             const char *MI,
                                                                             const char *T);

struct FfiResult_____AnyTransformation opendp_trans__make_sized_bounded_variance(unsigned int size,
                                                                                 const struct AnyObject *bounds,
                                                                                 unsigned int ddof,
                                                                                 const char *S);

struct FfiResult_____AnyTransformation opendp_trans__make_impute_uniform_float(const struct AnyObject *bounds,
                                                                               const char *TA);

struct FfiResult_____AnyTransformation opendp_trans__make_impute_constant(const struct AnyObject *constant,
                                                                          const char *DA);

struct FfiResult_____AnyTransformation opendp_trans__make_drop_null(const char *DA);

struct FfiResult_____AnyTransformation opendp_trans__make_find(const struct AnyObject *categories,
                                                               const char *TIA);

struct FfiResult_____AnyTransformation opendp_trans__make_find_bin(const struct AnyObject *edges,
                                                                   const char *TIA);

struct FfiResult_____AnyTransformation opendp_trans__make_index(const struct AnyObject *categories,
                                                                const struct AnyObject *null,
                                                                const char *TOA);

struct FfiResult_____AnyTransformation opendp_trans__make_lipschitz_float_mul(const void *constant,
                                                                              const struct AnyObject *bounds,
                                                                              const char *D,
                                                                              const char *M);

struct FfiResult_____AnyTransformation opendp_trans__make_clamp(const struct AnyObject *bounds,
                                                                const char *TA);

struct FfiResult_____AnyTransformation opendp_trans__make_unclamp(const struct AnyObject *bounds,
                                                                  const char *TA);

struct FfiResult_____AnyTransformation opendp_trans__make_cast(const char *TIA, const char *TOA);

struct FfiResult_____AnyTransformation opendp_trans__make_cast_default(const char *TIA,
                                                                       const char *TOA);

struct FfiResult_____AnyTransformation opendp_trans__make_cast_inherent(const char *TIA,
                                                                        const char *TOA);

struct FfiResult_____AnyTransformation opendp_trans__make_ordered_random(const char *TA);

struct FfiResult_____AnyTransformation opendp_trans__make_sized_ordered_random(unsigned int size,
                                                                               const char *MI,
                                                                               const char *TA);

struct FfiResult_____AnyTransformation opendp_trans__make_sized_bounded_ordered_random(unsigned int size,
                                                                                       const struct AnyObject *bounds,
                                                                                       const char *MI,
                                                                                       const char *TA);

struct FfiResult_____AnyTransformation opendp_trans__make_unordered(const char *TA);

struct FfiResult_____AnyTransformation opendp_trans__make_sized_unordered(unsigned int size,
                                                                          const char *MI,
                                                                          const char *TA);

struct FfiResult_____AnyTransformation opendp_trans__make_sized_bounded_unordered(unsigned int size,
                                                                                  const struct AnyObject *bounds,
                                                                                  const char *MI,
                                                                                  const char *TA);

struct FfiResult_____AnyTransformation opendp_trans__make_metric_bounded(unsigned int size,
                                                                         const char *MI,
                                                                         const char *TA);

struct FfiResult_____AnyTransformation opendp_trans__make_metric_unbounded(unsigned int size,
                                                                           const char *MI,
                                                                           const char *TA);

struct FfiResult_____AnyTransformation opendp_trans__make_bounded_resize(unsigned int size,
                                                                         const struct AnyObject *bounds,
                                                                         const void *constant,
                                                                         const char *MI,
                                                                         const char *MO,
                                                                         const char *TA);

struct FfiResult_____AnyTransformation opendp_trans__make_resize(unsigned int size,
                                                                 const struct AnyObject *constant,
                                                                 const char *MI,
                                                                 const char *MO,
                                                                 const char *TA);

struct FfiResult_____AnyMeasurement opendp_comb__make_population_amplification(const AnyMeasurement *measurement,
                                                                               unsigned int population_size);

struct FfiResult_____AnyMeasurement opendp_comb__make_chain_mt(const AnyMeasurement *measurement1,
                                                               const AnyTransformation *transformation0);

struct FfiResult_____AnyTransformation opendp_comb__make_chain_tt(const AnyTransformation *transformation1,
                                                                  const AnyTransformation *transformation0);

struct FfiResult_____AnyMeasurement opendp_comb__make_basic_composition(const struct AnyObject *measurements);

struct FfiResult_____AnyMeasurement opendp_comb__make_fix_delta(const AnyMeasurement *measurement,
                                                                const struct AnyObject *delta);
