// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <matrix/math.hpp>

namespace sym {

/**
 * This function was autogenerated from a symbolic function. Do not modify by hand.
 *
 * Symbolic function: predict_covariance
 *
 * Args:
 *     state: Matrix24_1
 *     P: Matrix23_23
 *     accel: Matrix31
 *     accel_var: Matrix31
 *     gyro: Matrix31
 *     gyro_var: Scalar
 *     dt: Scalar
 *
 * Outputs:
 *     res: Matrix23_23
 */
template <typename Scalar>
matrix::Matrix<Scalar, 23, 23> PredictCovariance(const matrix::Matrix<Scalar, 24, 1>& state,
                                                const matrix::Matrix<Scalar, 23, 23>& P,
                                                const matrix::Matrix<Scalar, 3, 1>& accel,
                                                const matrix::Matrix<Scalar, 3, 1>& accel_var,
                                                const matrix::Matrix<Scalar, 3, 1>& gyro,
                                                const Scalar gyro_var, const Scalar dt) {
  // Total ops: 1793

  // Input arrays

  // Intermediate terms (134)
  const Scalar _tmp0 = dt * gyro(1, 0);
  const Scalar _tmp1 = dt * state(11, 0);
  const Scalar _tmp2 = -_tmp0 + _tmp1;
  const Scalar _tmp3 = dt * gyro(2, 0);
  const Scalar _tmp4 = dt * state(12, 0);
  const Scalar _tmp5 = _tmp3 - _tmp4;
  const Scalar _tmp6 = P(0, 2) + P(1, 2) * _tmp5 + P(2, 2) * _tmp2 - P(9, 2) * dt;
  const Scalar _tmp7 = P(0, 1) + P(1, 1) * _tmp5 + P(2, 1) * _tmp2 - P(9, 1) * dt;
  const Scalar _tmp8 = P(0, 9) + P(1, 9) * _tmp5 + P(2, 9) * _tmp2 - P(9, 9) * dt;
  const Scalar _tmp9 = std::pow(dt, Scalar(2));
  const Scalar _tmp10 = _tmp9 * gyro_var;
  const Scalar _tmp11 = P(0, 0) + P(1, 0) * _tmp5 + P(2, 0) * _tmp2 - P(9, 0) * dt;
  const Scalar _tmp12 = P(0, 10) + P(1, 10) * _tmp5 + P(2, 10) * _tmp2 - P(9, 10) * dt;
  const Scalar _tmp13 = -_tmp3 + _tmp4;
  const Scalar _tmp14 = dt * gyro(0, 0);
  const Scalar _tmp15 = dt * state(10, 0);
  const Scalar _tmp16 = _tmp14 - _tmp15;
  const Scalar _tmp17 = P(0, 10) * _tmp13 + P(1, 10) - P(10, 10) * dt + P(2, 10) * _tmp16;
  const Scalar _tmp18 = P(0, 0) * _tmp13 + P(1, 0) - P(10, 0) * dt + P(2, 0) * _tmp16;
  const Scalar _tmp19 = P(0, 2) * _tmp13 + P(1, 2) - P(10, 2) * dt + P(2, 2) * _tmp16;
  const Scalar _tmp20 = P(0, 1) * _tmp13 + P(1, 1) - P(10, 1) * dt + P(2, 1) * _tmp16;
  const Scalar _tmp21 = P(0, 11) + P(1, 11) * _tmp5 + P(2, 11) * _tmp2 - P(9, 11) * dt;
  const Scalar _tmp22 = _tmp0 - _tmp1;
  const Scalar _tmp23 = -_tmp14 + _tmp15;
  const Scalar _tmp24 = P(0, 11) * _tmp13 + P(1, 11) - P(10, 11) * dt + P(2, 11) * _tmp16;
  const Scalar _tmp25 = P(0, 11) * _tmp22 + P(1, 11) * _tmp23 - P(11, 11) * dt + P(2, 11);
  const Scalar _tmp26 = P(0, 1) * _tmp22 + P(1, 1) * _tmp23 - P(11, 1) * dt + P(2, 1);
  const Scalar _tmp27 = P(0, 0) * _tmp22 + P(1, 0) * _tmp23 - P(11, 0) * dt + P(2, 0);
  const Scalar _tmp28 = P(0, 2) * _tmp22 + P(1, 2) * _tmp23 - P(11, 2) * dt + P(2, 2);
  const Scalar _tmp29 = 2 * state(0, 0);
  const Scalar _tmp30 = _tmp29 * state(3, 0);
  const Scalar _tmp31 = -_tmp30;
  const Scalar _tmp32 = 2 * state(1, 0);
  const Scalar _tmp33 = _tmp32 * state(2, 0);
  const Scalar _tmp34 = _tmp31 + _tmp33;
  const Scalar _tmp35 = accel(0, 0) - state(13, 0);
  const Scalar _tmp36 = std::pow(state(2, 0), Scalar(2));
  const Scalar _tmp37 = std::pow(state(1, 0), Scalar(2));
  const Scalar _tmp38 = -_tmp37;
  const Scalar _tmp39 = _tmp36 + _tmp38;
  const Scalar _tmp40 = std::pow(state(0, 0), Scalar(2));
  const Scalar _tmp41 = -_tmp40;
  const Scalar _tmp42 = std::pow(state(3, 0), Scalar(2));
  const Scalar _tmp43 = _tmp41 + _tmp42;
  const Scalar _tmp44 = accel(1, 0) - state(14, 0);
  const Scalar _tmp45 = dt * (_tmp34 * _tmp35 + _tmp44 * (_tmp39 + _tmp43));
  const Scalar _tmp46 = P(0, 12) + P(1, 12) * _tmp5 + P(2, 12) * _tmp2 - P(9, 12) * dt;
  const Scalar _tmp47 = -2 * _tmp42;
  const Scalar _tmp48 = -2 * _tmp36;
  const Scalar _tmp49 = _tmp47 + _tmp48 + 1;
  const Scalar _tmp50 = _tmp49 * dt;
  const Scalar _tmp51 = _tmp29 * state(2, 0);
  const Scalar _tmp52 = -_tmp51;
  const Scalar _tmp53 = _tmp32 * state(3, 0);
  const Scalar _tmp54 = -_tmp53;
  const Scalar _tmp55 = -_tmp42;
  const Scalar _tmp56 = _tmp40 + _tmp55;
  const Scalar _tmp57 = -_tmp36;
  const Scalar _tmp58 = _tmp37 + _tmp57;
  const Scalar _tmp59 = accel(2, 0) - state(15, 0);
  const Scalar _tmp60 = dt * (_tmp35 * (_tmp52 + _tmp54) + _tmp59 * (_tmp56 + _tmp58));
  const Scalar _tmp61 = _tmp51 + _tmp53;
  const Scalar _tmp62 = -_tmp33;
  const Scalar _tmp63 = dt * (_tmp44 * _tmp61 + _tmp59 * (_tmp30 + _tmp62));
  const Scalar _tmp64 = P(0, 13) + P(1, 13) * _tmp5 + P(2, 13) * _tmp2 - P(9, 13) * dt;
  const Scalar _tmp65 = _tmp34 * dt;
  const Scalar _tmp66 = P(0, 14) + P(1, 14) * _tmp5 + P(2, 14) * _tmp2 - P(9, 14) * dt;
  const Scalar _tmp67 = _tmp61 * dt;
  const Scalar _tmp68 = P(0, 3) + P(1, 3) * _tmp5 + P(2, 3) * _tmp2 - P(9, 3) * dt;
  const Scalar _tmp69 = P(0, 13) * _tmp13 + P(1, 13) - P(10, 13) * dt + P(2, 13) * _tmp16;
  const Scalar _tmp70 = P(0, 14) * _tmp13 + P(1, 14) - P(10, 14) * dt + P(2, 14) * _tmp16;
  const Scalar _tmp71 = P(0, 12) * _tmp13 + P(1, 12) - P(10, 12) * dt + P(2, 12) * _tmp16;
  const Scalar _tmp72 = P(0, 3) * _tmp13 + P(1, 3) - P(10, 3) * dt + P(2, 3) * _tmp16;
  const Scalar _tmp73 = P(0, 14) * _tmp22 + P(1, 14) * _tmp23 - P(11, 14) * dt + P(2, 14);
  const Scalar _tmp74 = P(0, 13) * _tmp22 + P(1, 13) * _tmp23 - P(11, 13) * dt + P(2, 13);
  const Scalar _tmp75 = P(0, 12) * _tmp22 + P(1, 12) * _tmp23 - P(11, 12) * dt + P(2, 12);
  const Scalar _tmp76 = P(0, 3) * _tmp22 + P(1, 3) * _tmp23 - P(11, 3) * dt + P(2, 3);
  const Scalar _tmp77 = P(0, 1) * _tmp63 + P(1, 1) * _tmp60 - P(12, 1) * _tmp50 -
                        P(13, 1) * _tmp65 - P(14, 1) * _tmp67 + P(2, 1) * _tmp45 + P(3, 1);
  const Scalar _tmp78 = P(0, 14) * _tmp63 + P(1, 14) * _tmp60 - P(12, 14) * _tmp50 -
                        P(13, 14) * _tmp65 - P(14, 14) * _tmp67 + P(2, 14) * _tmp45 + P(3, 14);
  const Scalar _tmp79 = P(0, 13) * _tmp63 + P(1, 13) * _tmp60 - P(12, 13) * _tmp50 -
                        P(13, 13) * _tmp65 - P(14, 13) * _tmp67 + P(2, 13) * _tmp45 + P(3, 13);
  const Scalar _tmp80 = P(0, 0) * _tmp63 + P(1, 0) * _tmp60 - P(12, 0) * _tmp50 -
                        P(13, 0) * _tmp65 - P(14, 0) * _tmp67 + P(2, 0) * _tmp45 + P(3, 0);
  const Scalar _tmp81 = _tmp9 * accel_var(0, 0);
  const Scalar _tmp82 = P(0, 2) * _tmp63 + P(1, 2) * _tmp60 - P(12, 2) * _tmp50 -
                        P(13, 2) * _tmp65 - P(14, 2) * _tmp67 + P(2, 2) * _tmp45 + P(3, 2);
  const Scalar _tmp83 = _tmp9 * accel_var(1, 0);
  const Scalar _tmp84 = _tmp9 * accel_var(2, 0);
  const Scalar _tmp85 = P(0, 12) * _tmp63 + P(1, 12) * _tmp60 - P(12, 12) * _tmp50 -
                        P(13, 12) * _tmp65 - P(14, 12) * _tmp67 + P(2, 12) * _tmp45 + P(3, 12);
  const Scalar _tmp86 = P(0, 3) * _tmp63 + P(1, 3) * _tmp60 - P(12, 3) * _tmp50 -
                        P(13, 3) * _tmp65 - P(14, 3) * _tmp67 + P(2, 3) * _tmp45 + P(3, 3);
  const Scalar _tmp87 = 2 * state(2, 0) * state(3, 0);
  const Scalar _tmp88 = _tmp29 * state(1, 0);
  const Scalar _tmp89 = -_tmp88;
  const Scalar _tmp90 = _tmp87 + _tmp89;
  const Scalar _tmp91 = dt * (_tmp44 * _tmp90 + _tmp59 * (_tmp43 + _tmp58));
  const Scalar _tmp92 = dt * (_tmp35 * (_tmp39 + _tmp56) + _tmp44 * (_tmp31 + _tmp62));
  const Scalar _tmp93 = 1 - 2 * _tmp37;
  const Scalar _tmp94 = _tmp47 + _tmp93;
  const Scalar _tmp95 = _tmp94 * dt;
  const Scalar _tmp96 = _tmp90 * dt;
  const Scalar _tmp97 = _tmp30 + _tmp33;
  const Scalar _tmp98 = -_tmp87;
  const Scalar _tmp99 = dt * (_tmp35 * (_tmp88 + _tmp98) + _tmp59 * _tmp97);
  const Scalar _tmp100 = _tmp97 * dt;
  const Scalar _tmp101 = P(0, 4) + P(1, 4) * _tmp5 + P(2, 4) * _tmp2 - P(9, 4) * dt;
  const Scalar _tmp102 = P(0, 4) * _tmp13 + P(1, 4) - P(10, 4) * dt + P(2, 4) * _tmp16;
  const Scalar _tmp103 = _tmp74 * dt;
  const Scalar _tmp104 = P(0, 4) * _tmp22 + P(1, 4) * _tmp23 - P(11, 4) * dt + P(2, 4);
  const Scalar _tmp105 = _tmp81 * _tmp97;
  const Scalar _tmp106 = _tmp84 * _tmp90;
  const Scalar _tmp107 = P(0, 4) * _tmp63 + P(1, 4) * _tmp60 - P(12, 4) * _tmp50 -
                         P(13, 4) * _tmp65 - P(14, 4) * _tmp67 + P(2, 4) * _tmp45 + P(3, 4);
  const Scalar _tmp108 = P(0, 14) * _tmp91 + P(1, 14) * _tmp99 - P(12, 14) * _tmp100 -
                         P(13, 14) * _tmp95 - P(14, 14) * _tmp96 + P(2, 14) * _tmp92 + P(4, 14);
  const Scalar _tmp109 = P(0, 0) * _tmp91 + P(1, 0) * _tmp99 - P(12, 0) * _tmp100 -
                         P(13, 0) * _tmp95 - P(14, 0) * _tmp96 + P(2, 0) * _tmp92 + P(4, 0);
  const Scalar _tmp110 = P(0, 13) * _tmp91 + P(1, 13) * _tmp99 - P(12, 13) * _tmp100 -
                         P(13, 13) * _tmp95 - P(14, 13) * _tmp96 + P(2, 13) * _tmp92 + P(4, 13);
  const Scalar _tmp111 = P(0, 12) * _tmp91 + P(1, 12) * _tmp99 - P(12, 12) * _tmp100 -
                         P(13, 12) * _tmp95 - P(14, 12) * _tmp96 + P(2, 12) * _tmp92 + P(4, 12);
  const Scalar _tmp112 = P(0, 1) * _tmp91 + P(1, 1) * _tmp99 - P(12, 1) * _tmp100 -
                         P(13, 1) * _tmp95 - P(14, 1) * _tmp96 + P(2, 1) * _tmp92 + P(4, 1);
  const Scalar _tmp113 = P(0, 2) * _tmp91 + P(1, 2) * _tmp99 - P(12, 2) * _tmp100 -
                         P(13, 2) * _tmp95 - P(14, 2) * _tmp96 + P(2, 2) * _tmp92 + P(4, 2);
  const Scalar _tmp114 = P(0, 4) * _tmp91 + P(1, 4) * _tmp99 - P(12, 4) * _tmp100 -
                         P(13, 4) * _tmp95 - P(14, 4) * _tmp96 + P(2, 4) * _tmp92 + P(4, 4);
  const Scalar _tmp115 =
      dt * (_tmp44 * (_tmp38 + _tmp40 + _tmp42 + _tmp57) + _tmp59 * (_tmp89 + _tmp98));
  const Scalar _tmp116 = _tmp48 + _tmp93;
  const Scalar _tmp117 = _tmp116 * dt;
  const Scalar _tmp118 = _tmp87 + _tmp88;
  const Scalar _tmp119 = _tmp118 * dt;
  const Scalar _tmp120 = dt * (_tmp118 * _tmp35 + _tmp44 * (_tmp51 + _tmp54));
  const Scalar _tmp121 = _tmp52 + _tmp53;
  const Scalar _tmp122 = dt * (_tmp121 * _tmp59 + _tmp35 * (_tmp36 + _tmp37 + _tmp41 + _tmp55));
  const Scalar _tmp123 = _tmp121 * dt;
  const Scalar _tmp124 = P(0, 5) + P(1, 5) * _tmp5 + P(2, 5) * _tmp2 - P(9, 5) * dt;
  const Scalar _tmp125 = P(0, 5) * _tmp13 + P(1, 5) - P(10, 5) * dt + P(2, 5) * _tmp16;
  const Scalar _tmp126 = P(0, 5) * _tmp22 + P(1, 5) * _tmp23 - P(11, 5) * dt + P(2, 5);
  const Scalar _tmp127 = _tmp118 * _tmp83;
  const Scalar _tmp128 = P(0, 5) * _tmp63 + P(1, 5) * _tmp60 - P(12, 5) * _tmp50 -
                         P(13, 5) * _tmp65 - P(14, 5) * _tmp67 + P(2, 5) * _tmp45 + P(3, 5);
  const Scalar _tmp129 = P(0, 5) * _tmp91 + P(1, 5) * _tmp99 - P(12, 5) * _tmp100 -
                         P(13, 5) * _tmp95 - P(14, 5) * _tmp96 + P(2, 5) * _tmp92 + P(4, 5);
  const Scalar _tmp130 = P(0, 13) * _tmp115 + P(1, 13) * _tmp122 - P(12, 13) * _tmp123 -
                         P(13, 13) * _tmp119 - P(14, 13) * _tmp117 + P(2, 13) * _tmp120 + P(5, 13);
  const Scalar _tmp131 = P(0, 14) * _tmp115 + P(1, 14) * _tmp122 - P(12, 14) * _tmp123 -
                         P(13, 14) * _tmp119 - P(14, 14) * _tmp117 + P(2, 14) * _tmp120 + P(5, 14);
  const Scalar _tmp132 = P(0, 12) * _tmp115 + P(1, 12) * _tmp122 - P(12, 12) * _tmp123 -
                         P(13, 12) * _tmp119 - P(14, 12) * _tmp117 + P(2, 12) * _tmp120 + P(5, 12);
  const Scalar _tmp133 = P(0, 5) * _tmp115 + P(1, 5) * _tmp122 - P(12, 5) * _tmp123 -
                         P(13, 5) * _tmp119 - P(14, 5) * _tmp117 + P(2, 5) * _tmp120 + P(5, 5);

  // Output terms (1)
  matrix::Matrix<Scalar, 23, 23> _res;

  _res(0, 0) = _tmp10 + _tmp11 + _tmp2 * _tmp6 + _tmp5 * _tmp7 - _tmp8 * dt;
  _res(1, 0) = 0;
  _res(2, 0) = 0;
  _res(3, 0) = 0;
  _res(4, 0) = 0;
  _res(5, 0) = 0;
  _res(6, 0) = 0;
  _res(7, 0) = 0;
  _res(8, 0) = 0;
  _res(9, 0) = 0;
  _res(10, 0) = 0;
  _res(11, 0) = 0;
  _res(12, 0) = 0;
  _res(13, 0) = 0;
  _res(14, 0) = 0;
  _res(15, 0) = 0;
  _res(16, 0) = 0;
  _res(17, 0) = 0;
  _res(18, 0) = 0;
  _res(19, 0) = 0;
  _res(20, 0) = 0;
  _res(21, 0) = 0;
  _res(22, 0) = 0;
  _res(0, 1) = _tmp11 * _tmp13 - _tmp12 * dt + _tmp16 * _tmp6 + _tmp7;
  _res(1, 1) = _tmp10 + _tmp13 * _tmp18 + _tmp16 * _tmp19 - _tmp17 * dt + _tmp20;
  _res(2, 1) = 0;
  _res(3, 1) = 0;
  _res(4, 1) = 0;
  _res(5, 1) = 0;
  _res(6, 1) = 0;
  _res(7, 1) = 0;
  _res(8, 1) = 0;
  _res(9, 1) = 0;
  _res(10, 1) = 0;
  _res(11, 1) = 0;
  _res(12, 1) = 0;
  _res(13, 1) = 0;
  _res(14, 1) = 0;
  _res(15, 1) = 0;
  _res(16, 1) = 0;
  _res(17, 1) = 0;
  _res(18, 1) = 0;
  _res(19, 1) = 0;
  _res(20, 1) = 0;
  _res(21, 1) = 0;
  _res(22, 1) = 0;
  _res(0, 2) = _tmp11 * _tmp22 - _tmp21 * dt + _tmp23 * _tmp7 + _tmp6;
  _res(1, 2) = _tmp18 * _tmp22 + _tmp19 + _tmp20 * _tmp23 - _tmp24 * dt;
  _res(2, 2) = _tmp10 + _tmp22 * _tmp27 + _tmp23 * _tmp26 - _tmp25 * dt + _tmp28;
  _res(3, 2) = 0;
  _res(4, 2) = 0;
  _res(5, 2) = 0;
  _res(6, 2) = 0;
  _res(7, 2) = 0;
  _res(8, 2) = 0;
  _res(9, 2) = 0;
  _res(10, 2) = 0;
  _res(11, 2) = 0;
  _res(12, 2) = 0;
  _res(13, 2) = 0;
  _res(14, 2) = 0;
  _res(15, 2) = 0;
  _res(16, 2) = 0;
  _res(17, 2) = 0;
  _res(18, 2) = 0;
  _res(19, 2) = 0;
  _res(20, 2) = 0;
  _res(21, 2) = 0;
  _res(22, 2) = 0;
  _res(0, 3) = _tmp11 * _tmp63 + _tmp45 * _tmp6 - _tmp46 * _tmp50 + _tmp60 * _tmp7 -
               _tmp64 * _tmp65 - _tmp66 * _tmp67 + _tmp68;
  _res(1, 3) = _tmp18 * _tmp63 + _tmp19 * _tmp45 + _tmp20 * _tmp60 - _tmp50 * _tmp71 -
               _tmp65 * _tmp69 - _tmp67 * _tmp70 + _tmp72;
  _res(2, 3) = _tmp26 * _tmp60 + _tmp27 * _tmp63 + _tmp28 * _tmp45 - _tmp50 * _tmp75 -
               _tmp65 * _tmp74 - _tmp67 * _tmp73 + _tmp76;
  _res(3, 3) = std::pow(_tmp34, Scalar(2)) * _tmp83 + _tmp45 * _tmp82 +
               std::pow(_tmp49, Scalar(2)) * _tmp81 - _tmp50 * _tmp85 + _tmp60 * _tmp77 +
               std::pow(_tmp61, Scalar(2)) * _tmp84 + _tmp63 * _tmp80 - _tmp65 * _tmp79 -
               _tmp67 * _tmp78 + _tmp86;
  _res(4, 3) = 0;
  _res(5, 3) = 0;
  _res(6, 3) = 0;
  _res(7, 3) = 0;
  _res(8, 3) = 0;
  _res(9, 3) = 0;
  _res(10, 3) = 0;
  _res(11, 3) = 0;
  _res(12, 3) = 0;
  _res(13, 3) = 0;
  _res(14, 3) = 0;
  _res(15, 3) = 0;
  _res(16, 3) = 0;
  _res(17, 3) = 0;
  _res(18, 3) = 0;
  _res(19, 3) = 0;
  _res(20, 3) = 0;
  _res(21, 3) = 0;
  _res(22, 3) = 0;
  _res(0, 4) = -_tmp100 * _tmp46 + _tmp101 + _tmp11 * _tmp91 + _tmp6 * _tmp92 - _tmp64 * _tmp95 -
               _tmp66 * _tmp96 + _tmp7 * _tmp99;
  _res(1, 4) = -_tmp100 * _tmp71 + _tmp102 + _tmp18 * _tmp91 + _tmp19 * _tmp92 + _tmp20 * _tmp99 -
               _tmp69 * _tmp95 - _tmp70 * _tmp96;
  _res(2, 4) = -_tmp100 * _tmp75 - _tmp103 * _tmp94 + _tmp104 + _tmp26 * _tmp99 + _tmp27 * _tmp91 +
               _tmp28 * _tmp92 - _tmp73 * _tmp96;
  _res(3, 4) = -_tmp100 * _tmp85 + _tmp105 * _tmp49 + _tmp106 * _tmp61 + _tmp107 +
               _tmp34 * _tmp83 * _tmp94 + _tmp77 * _tmp99 - _tmp78 * _tmp96 - _tmp79 * _tmp95 +
               _tmp80 * _tmp91 + _tmp82 * _tmp92;
  _res(4, 4) = -_tmp100 * _tmp111 - _tmp108 * _tmp96 + _tmp109 * _tmp91 - _tmp110 * _tmp95 +
               _tmp112 * _tmp99 + _tmp113 * _tmp92 + _tmp114 +
               _tmp81 * std::pow(_tmp97, Scalar(2)) + _tmp83 * std::pow(_tmp94, Scalar(2)) +
               _tmp84 * std::pow(_tmp90, Scalar(2));
  _res(5, 4) = 0;
  _res(6, 4) = 0;
  _res(7, 4) = 0;
  _res(8, 4) = 0;
  _res(9, 4) = 0;
  _res(10, 4) = 0;
  _res(11, 4) = 0;
  _res(12, 4) = 0;
  _res(13, 4) = 0;
  _res(14, 4) = 0;
  _res(15, 4) = 0;
  _res(16, 4) = 0;
  _res(17, 4) = 0;
  _res(18, 4) = 0;
  _res(19, 4) = 0;
  _res(20, 4) = 0;
  _res(21, 4) = 0;
  _res(22, 4) = 0;
  _res(0, 5) = _tmp11 * _tmp115 - _tmp117 * _tmp66 - _tmp119 * _tmp64 + _tmp120 * _tmp6 +
               _tmp122 * _tmp7 - _tmp123 * _tmp46 + _tmp124;
  _res(1, 5) = _tmp115 * _tmp18 - _tmp117 * _tmp70 - _tmp119 * _tmp69 + _tmp120 * _tmp19 +
               _tmp122 * _tmp20 - _tmp123 * _tmp71 + _tmp125;
  _res(2, 5) = -_tmp103 * _tmp118 + _tmp115 * _tmp27 - _tmp117 * _tmp73 + _tmp120 * _tmp28 +
               _tmp122 * _tmp26 - _tmp123 * _tmp75 + _tmp126;
  _res(3, 5) = _tmp115 * _tmp80 + _tmp116 * _tmp61 * _tmp84 - _tmp117 * _tmp78 - _tmp119 * _tmp79 +
               _tmp120 * _tmp82 + _tmp121 * _tmp49 * _tmp81 + _tmp122 * _tmp77 - _tmp123 * _tmp85 +
               _tmp127 * _tmp34 + _tmp128;
  _res(4, 5) = _tmp105 * _tmp121 + _tmp106 * _tmp116 - _tmp108 * _tmp117 + _tmp109 * _tmp115 -
               _tmp110 * _tmp119 - _tmp111 * _tmp123 + _tmp112 * _tmp122 + _tmp113 * _tmp120 +
               _tmp127 * _tmp94 + _tmp129;
  _res(5, 5) = _tmp115 * (P(0, 0) * _tmp115 + P(1, 0) * _tmp122 - P(12, 0) * _tmp123 -
                          P(13, 0) * _tmp119 - P(14, 0) * _tmp117 + P(2, 0) * _tmp120 + P(5, 0)) +
               std::pow(_tmp116, Scalar(2)) * _tmp84 - _tmp117 * _tmp131 +
               std::pow(_tmp118, Scalar(2)) * _tmp83 - _tmp119 * _tmp130 +
               _tmp120 * (P(0, 2) * _tmp115 + P(1, 2) * _tmp122 - P(12, 2) * _tmp123 -
                          P(13, 2) * _tmp119 - P(14, 2) * _tmp117 + P(2, 2) * _tmp120 + P(5, 2)) +
               std::pow(_tmp121, Scalar(2)) * _tmp81 +
               _tmp122 * (P(0, 1) * _tmp115 + P(1, 1) * _tmp122 - P(12, 1) * _tmp123 -
                          P(13, 1) * _tmp119 - P(14, 1) * _tmp117 + P(2, 1) * _tmp120 + P(5, 1)) -
               _tmp123 * _tmp132 + _tmp133;
  _res(6, 5) = 0;
  _res(7, 5) = 0;
  _res(8, 5) = 0;
  _res(9, 5) = 0;
  _res(10, 5) = 0;
  _res(11, 5) = 0;
  _res(12, 5) = 0;
  _res(13, 5) = 0;
  _res(14, 5) = 0;
  _res(15, 5) = 0;
  _res(16, 5) = 0;
  _res(17, 5) = 0;
  _res(18, 5) = 0;
  _res(19, 5) = 0;
  _res(20, 5) = 0;
  _res(21, 5) = 0;
  _res(22, 5) = 0;
  _res(0, 6) = P(0, 6) + P(1, 6) * _tmp5 + P(2, 6) * _tmp2 - P(9, 6) * dt + _tmp68 * dt;
  _res(1, 6) = P(0, 6) * _tmp13 + P(1, 6) - P(10, 6) * dt + P(2, 6) * _tmp16 + _tmp72 * dt;
  _res(2, 6) = P(0, 6) * _tmp22 + P(1, 6) * _tmp23 - P(11, 6) * dt + P(2, 6) + _tmp76 * dt;
  _res(3, 6) = P(0, 6) * _tmp63 + P(1, 6) * _tmp60 - P(12, 6) * _tmp50 - P(13, 6) * _tmp65 -
               P(14, 6) * _tmp67 + P(2, 6) * _tmp45 + P(3, 6) + _tmp86 * dt;
  _res(4, 6) = P(0, 6) * _tmp91 + P(1, 6) * _tmp99 - P(12, 6) * _tmp100 - P(13, 6) * _tmp95 -
               P(14, 6) * _tmp96 + P(2, 6) * _tmp92 + P(4, 6) +
               dt * (P(0, 3) * _tmp91 + P(1, 3) * _tmp99 - P(12, 3) * _tmp100 - P(13, 3) * _tmp95 -
                     P(14, 3) * _tmp96 + P(2, 3) * _tmp92 + P(4, 3));
  _res(5, 6) = P(0, 6) * _tmp115 + P(1, 6) * _tmp122 - P(12, 6) * _tmp123 - P(13, 6) * _tmp119 -
               P(14, 6) * _tmp117 + P(2, 6) * _tmp120 + P(5, 6) +
               dt * (P(0, 3) * _tmp115 + P(1, 3) * _tmp122 - P(12, 3) * _tmp123 -
                     P(13, 3) * _tmp119 - P(14, 3) * _tmp117 + P(2, 3) * _tmp120 + P(5, 3));
  _res(6, 6) = P(3, 6) * dt + P(6, 6) + dt * (P(3, 3) * dt + P(6, 3));
  _res(7, 6) = 0;
  _res(8, 6) = 0;
  _res(9, 6) = 0;
  _res(10, 6) = 0;
  _res(11, 6) = 0;
  _res(12, 6) = 0;
  _res(13, 6) = 0;
  _res(14, 6) = 0;
  _res(15, 6) = 0;
  _res(16, 6) = 0;
  _res(17, 6) = 0;
  _res(18, 6) = 0;
  _res(19, 6) = 0;
  _res(20, 6) = 0;
  _res(21, 6) = 0;
  _res(22, 6) = 0;
  _res(0, 7) = P(0, 7) + P(1, 7) * _tmp5 + P(2, 7) * _tmp2 - P(9, 7) * dt + _tmp101 * dt;
  _res(1, 7) = P(0, 7) * _tmp13 + P(1, 7) - P(10, 7) * dt + P(2, 7) * _tmp16 + _tmp102 * dt;
  _res(2, 7) = P(0, 7) * _tmp22 + P(1, 7) * _tmp23 - P(11, 7) * dt + P(2, 7) + _tmp104 * dt;
  _res(3, 7) = P(0, 7) * _tmp63 + P(1, 7) * _tmp60 - P(12, 7) * _tmp50 - P(13, 7) * _tmp65 -
               P(14, 7) * _tmp67 + P(2, 7) * _tmp45 + P(3, 7) + _tmp107 * dt;
  _res(4, 7) = P(0, 7) * _tmp91 + P(1, 7) * _tmp99 - P(12, 7) * _tmp100 - P(13, 7) * _tmp95 -
               P(14, 7) * _tmp96 + P(2, 7) * _tmp92 + P(4, 7) + _tmp114 * dt;
  _res(5, 7) = P(0, 7) * _tmp115 + P(1, 7) * _tmp122 - P(12, 7) * _tmp123 - P(13, 7) * _tmp119 -
               P(14, 7) * _tmp117 + P(2, 7) * _tmp120 + P(5, 7) +
               dt * (P(0, 4) * _tmp115 + P(1, 4) * _tmp122 - P(12, 4) * _tmp123 -
                     P(13, 4) * _tmp119 - P(14, 4) * _tmp117 + P(2, 4) * _tmp120 + P(5, 4));
  _res(6, 7) = P(3, 7) * dt + P(6, 7) + dt * (P(3, 4) * dt + P(6, 4));
  _res(7, 7) = P(4, 7) * dt + P(7, 7) + dt * (P(4, 4) * dt + P(7, 4));
  _res(8, 7) = 0;
  _res(9, 7) = 0;
  _res(10, 7) = 0;
  _res(11, 7) = 0;
  _res(12, 7) = 0;
  _res(13, 7) = 0;
  _res(14, 7) = 0;
  _res(15, 7) = 0;
  _res(16, 7) = 0;
  _res(17, 7) = 0;
  _res(18, 7) = 0;
  _res(19, 7) = 0;
  _res(20, 7) = 0;
  _res(21, 7) = 0;
  _res(22, 7) = 0;
  _res(0, 8) = P(0, 8) + P(1, 8) * _tmp5 + P(2, 8) * _tmp2 - P(9, 8) * dt + _tmp124 * dt;
  _res(1, 8) = P(0, 8) * _tmp13 + P(1, 8) - P(10, 8) * dt + P(2, 8) * _tmp16 + _tmp125 * dt;
  _res(2, 8) = P(0, 8) * _tmp22 + P(1, 8) * _tmp23 - P(11, 8) * dt + P(2, 8) + _tmp126 * dt;
  _res(3, 8) = P(0, 8) * _tmp63 + P(1, 8) * _tmp60 - P(12, 8) * _tmp50 - P(13, 8) * _tmp65 -
               P(14, 8) * _tmp67 + P(2, 8) * _tmp45 + P(3, 8) + _tmp128 * dt;
  _res(4, 8) = P(0, 8) * _tmp91 + P(1, 8) * _tmp99 - P(12, 8) * _tmp100 - P(13, 8) * _tmp95 -
               P(14, 8) * _tmp96 + P(2, 8) * _tmp92 + P(4, 8) + _tmp129 * dt;
  _res(5, 8) = P(0, 8) * _tmp115 + P(1, 8) * _tmp122 - P(12, 8) * _tmp123 - P(13, 8) * _tmp119 -
               P(14, 8) * _tmp117 + P(2, 8) * _tmp120 + P(5, 8) + _tmp133 * dt;
  _res(6, 8) = P(3, 8) * dt + P(6, 8) + dt * (P(3, 5) * dt + P(6, 5));
  _res(7, 8) = P(4, 8) * dt + P(7, 8) + dt * (P(4, 5) * dt + P(7, 5));
  _res(8, 8) = P(5, 8) * dt + P(8, 8) + dt * (P(5, 5) * dt + P(8, 5));
  _res(9, 8) = 0;
  _res(10, 8) = 0;
  _res(11, 8) = 0;
  _res(12, 8) = 0;
  _res(13, 8) = 0;
  _res(14, 8) = 0;
  _res(15, 8) = 0;
  _res(16, 8) = 0;
  _res(17, 8) = 0;
  _res(18, 8) = 0;
  _res(19, 8) = 0;
  _res(20, 8) = 0;
  _res(21, 8) = 0;
  _res(22, 8) = 0;
  _res(0, 9) = _tmp8;
  _res(1, 9) = P(0, 9) * _tmp13 + P(1, 9) - P(10, 9) * dt + P(2, 9) * _tmp16;
  _res(2, 9) = P(0, 9) * _tmp22 + P(1, 9) * _tmp23 - P(11, 9) * dt + P(2, 9);
  _res(3, 9) = P(0, 9) * _tmp63 + P(1, 9) * _tmp60 - P(12, 9) * _tmp50 - P(13, 9) * _tmp65 -
               P(14, 9) * _tmp67 + P(2, 9) * _tmp45 + P(3, 9);
  _res(4, 9) = P(0, 9) * _tmp91 + P(1, 9) * _tmp99 - P(12, 9) * _tmp100 - P(13, 9) * _tmp95 -
               P(14, 9) * _tmp96 + P(2, 9) * _tmp92 + P(4, 9);
  _res(5, 9) = P(0, 9) * _tmp115 + P(1, 9) * _tmp122 - P(12, 9) * _tmp123 - P(13, 9) * _tmp119 -
               P(14, 9) * _tmp117 + P(2, 9) * _tmp120 + P(5, 9);
  _res(6, 9) = P(3, 9) * dt + P(6, 9);
  _res(7, 9) = P(4, 9) * dt + P(7, 9);
  _res(8, 9) = P(5, 9) * dt + P(8, 9);
  _res(9, 9) = P(9, 9);
  _res(10, 9) = 0;
  _res(11, 9) = 0;
  _res(12, 9) = 0;
  _res(13, 9) = 0;
  _res(14, 9) = 0;
  _res(15, 9) = 0;
  _res(16, 9) = 0;
  _res(17, 9) = 0;
  _res(18, 9) = 0;
  _res(19, 9) = 0;
  _res(20, 9) = 0;
  _res(21, 9) = 0;
  _res(22, 9) = 0;
  _res(0, 10) = _tmp12;
  _res(1, 10) = _tmp17;
  _res(2, 10) = P(0, 10) * _tmp22 + P(1, 10) * _tmp23 - P(11, 10) * dt + P(2, 10);
  _res(3, 10) = P(0, 10) * _tmp63 + P(1, 10) * _tmp60 - P(12, 10) * _tmp50 - P(13, 10) * _tmp65 -
                P(14, 10) * _tmp67 + P(2, 10) * _tmp45 + P(3, 10);
  _res(4, 10) = P(0, 10) * _tmp91 + P(1, 10) * _tmp99 - P(12, 10) * _tmp100 - P(13, 10) * _tmp95 -
                P(14, 10) * _tmp96 + P(2, 10) * _tmp92 + P(4, 10);
  _res(5, 10) = P(0, 10) * _tmp115 + P(1, 10) * _tmp122 - P(12, 10) * _tmp123 -
                P(13, 10) * _tmp119 - P(14, 10) * _tmp117 + P(2, 10) * _tmp120 + P(5, 10);
  _res(6, 10) = P(3, 10) * dt + P(6, 10);
  _res(7, 10) = P(4, 10) * dt + P(7, 10);
  _res(8, 10) = P(5, 10) * dt + P(8, 10);
  _res(9, 10) = P(9, 10);
  _res(10, 10) = P(10, 10);
  _res(11, 10) = 0;
  _res(12, 10) = 0;
  _res(13, 10) = 0;
  _res(14, 10) = 0;
  _res(15, 10) = 0;
  _res(16, 10) = 0;
  _res(17, 10) = 0;
  _res(18, 10) = 0;
  _res(19, 10) = 0;
  _res(20, 10) = 0;
  _res(21, 10) = 0;
  _res(22, 10) = 0;
  _res(0, 11) = _tmp21;
  _res(1, 11) = _tmp24;
  _res(2, 11) = _tmp25;
  _res(3, 11) = P(0, 11) * _tmp63 + P(1, 11) * _tmp60 - P(12, 11) * _tmp50 - P(13, 11) * _tmp65 -
                P(14, 11) * _tmp67 + P(2, 11) * _tmp45 + P(3, 11);
  _res(4, 11) = P(0, 11) * _tmp91 + P(1, 11) * _tmp99 - P(12, 11) * _tmp100 - P(13, 11) * _tmp95 -
                P(14, 11) * _tmp96 + P(2, 11) * _tmp92 + P(4, 11);
  _res(5, 11) = P(0, 11) * _tmp115 + P(1, 11) * _tmp122 - P(12, 11) * _tmp123 -
                P(13, 11) * _tmp119 - P(14, 11) * _tmp117 + P(2, 11) * _tmp120 + P(5, 11);
  _res(6, 11) = P(3, 11) * dt + P(6, 11);
  _res(7, 11) = P(4, 11) * dt + P(7, 11);
  _res(8, 11) = P(5, 11) * dt + P(8, 11);
  _res(9, 11) = P(9, 11);
  _res(10, 11) = P(10, 11);
  _res(11, 11) = P(11, 11);
  _res(12, 11) = 0;
  _res(13, 11) = 0;
  _res(14, 11) = 0;
  _res(15, 11) = 0;
  _res(16, 11) = 0;
  _res(17, 11) = 0;
  _res(18, 11) = 0;
  _res(19, 11) = 0;
  _res(20, 11) = 0;
  _res(21, 11) = 0;
  _res(22, 11) = 0;
  _res(0, 12) = _tmp46;
  _res(1, 12) = _tmp71;
  _res(2, 12) = _tmp75;
  _res(3, 12) = _tmp85;
  _res(4, 12) = _tmp111;
  _res(5, 12) = _tmp132;
  _res(6, 12) = P(3, 12) * dt + P(6, 12);
  _res(7, 12) = P(4, 12) * dt + P(7, 12);
  _res(8, 12) = P(5, 12) * dt + P(8, 12);
  _res(9, 12) = P(9, 12);
  _res(10, 12) = P(10, 12);
  _res(11, 12) = P(11, 12);
  _res(12, 12) = P(12, 12);
  _res(13, 12) = 0;
  _res(14, 12) = 0;
  _res(15, 12) = 0;
  _res(16, 12) = 0;
  _res(17, 12) = 0;
  _res(18, 12) = 0;
  _res(19, 12) = 0;
  _res(20, 12) = 0;
  _res(21, 12) = 0;
  _res(22, 12) = 0;
  _res(0, 13) = _tmp64;
  _res(1, 13) = _tmp69;
  _res(2, 13) = _tmp74;
  _res(3, 13) = _tmp79;
  _res(4, 13) = _tmp110;
  _res(5, 13) = _tmp130;
  _res(6, 13) = P(3, 13) * dt + P(6, 13);
  _res(7, 13) = P(4, 13) * dt + P(7, 13);
  _res(8, 13) = P(5, 13) * dt + P(8, 13);
  _res(9, 13) = P(9, 13);
  _res(10, 13) = P(10, 13);
  _res(11, 13) = P(11, 13);
  _res(12, 13) = P(12, 13);
  _res(13, 13) = P(13, 13);
  _res(14, 13) = 0;
  _res(15, 13) = 0;
  _res(16, 13) = 0;
  _res(17, 13) = 0;
  _res(18, 13) = 0;
  _res(19, 13) = 0;
  _res(20, 13) = 0;
  _res(21, 13) = 0;
  _res(22, 13) = 0;
  _res(0, 14) = _tmp66;
  _res(1, 14) = _tmp70;
  _res(2, 14) = _tmp73;
  _res(3, 14) = _tmp78;
  _res(4, 14) = _tmp108;
  _res(5, 14) = _tmp131;
  _res(6, 14) = P(3, 14) * dt + P(6, 14);
  _res(7, 14) = P(4, 14) * dt + P(7, 14);
  _res(8, 14) = P(5, 14) * dt + P(8, 14);
  _res(9, 14) = P(9, 14);
  _res(10, 14) = P(10, 14);
  _res(11, 14) = P(11, 14);
  _res(12, 14) = P(12, 14);
  _res(13, 14) = P(13, 14);
  _res(14, 14) = P(14, 14);
  _res(15, 14) = 0;
  _res(16, 14) = 0;
  _res(17, 14) = 0;
  _res(18, 14) = 0;
  _res(19, 14) = 0;
  _res(20, 14) = 0;
  _res(21, 14) = 0;
  _res(22, 14) = 0;
  _res(0, 15) = P(0, 15) + P(1, 15) * _tmp5 + P(2, 15) * _tmp2 - P(9, 15) * dt;
  _res(1, 15) = P(0, 15) * _tmp13 + P(1, 15) - P(10, 15) * dt + P(2, 15) * _tmp16;
  _res(2, 15) = P(0, 15) * _tmp22 + P(1, 15) * _tmp23 - P(11, 15) * dt + P(2, 15);
  _res(3, 15) = P(0, 15) * _tmp63 + P(1, 15) * _tmp60 - P(12, 15) * _tmp50 - P(13, 15) * _tmp65 -
                P(14, 15) * _tmp67 + P(2, 15) * _tmp45 + P(3, 15);
  _res(4, 15) = P(0, 15) * _tmp91 + P(1, 15) * _tmp99 - P(12, 15) * _tmp100 - P(13, 15) * _tmp95 -
                P(14, 15) * _tmp96 + P(2, 15) * _tmp92 + P(4, 15);
  _res(5, 15) = P(0, 15) * _tmp115 + P(1, 15) * _tmp122 - P(12, 15) * _tmp123 -
                P(13, 15) * _tmp119 - P(14, 15) * _tmp117 + P(2, 15) * _tmp120 + P(5, 15);
  _res(6, 15) = P(3, 15) * dt + P(6, 15);
  _res(7, 15) = P(4, 15) * dt + P(7, 15);
  _res(8, 15) = P(5, 15) * dt + P(8, 15);
  _res(9, 15) = P(9, 15);
  _res(10, 15) = P(10, 15);
  _res(11, 15) = P(11, 15);
  _res(12, 15) = P(12, 15);
  _res(13, 15) = P(13, 15);
  _res(14, 15) = P(14, 15);
  _res(15, 15) = P(15, 15);
  _res(16, 15) = 0;
  _res(17, 15) = 0;
  _res(18, 15) = 0;
  _res(19, 15) = 0;
  _res(20, 15) = 0;
  _res(21, 15) = 0;
  _res(22, 15) = 0;
  _res(0, 16) = P(0, 16) + P(1, 16) * _tmp5 + P(2, 16) * _tmp2 - P(9, 16) * dt;
  _res(1, 16) = P(0, 16) * _tmp13 + P(1, 16) - P(10, 16) * dt + P(2, 16) * _tmp16;
  _res(2, 16) = P(0, 16) * _tmp22 + P(1, 16) * _tmp23 - P(11, 16) * dt + P(2, 16);
  _res(3, 16) = P(0, 16) * _tmp63 + P(1, 16) * _tmp60 - P(12, 16) * _tmp50 - P(13, 16) * _tmp65 -
                P(14, 16) * _tmp67 + P(2, 16) * _tmp45 + P(3, 16);
  _res(4, 16) = P(0, 16) * _tmp91 + P(1, 16) * _tmp99 - P(12, 16) * _tmp100 - P(13, 16) * _tmp95 -
                P(14, 16) * _tmp96 + P(2, 16) * _tmp92 + P(4, 16);
  _res(5, 16) = P(0, 16) * _tmp115 + P(1, 16) * _tmp122 - P(12, 16) * _tmp123 -
                P(13, 16) * _tmp119 - P(14, 16) * _tmp117 + P(2, 16) * _tmp120 + P(5, 16);
  _res(6, 16) = P(3, 16) * dt + P(6, 16);
  _res(7, 16) = P(4, 16) * dt + P(7, 16);
  _res(8, 16) = P(5, 16) * dt + P(8, 16);
  _res(9, 16) = P(9, 16);
  _res(10, 16) = P(10, 16);
  _res(11, 16) = P(11, 16);
  _res(12, 16) = P(12, 16);
  _res(13, 16) = P(13, 16);
  _res(14, 16) = P(14, 16);
  _res(15, 16) = P(15, 16);
  _res(16, 16) = P(16, 16);
  _res(17, 16) = 0;
  _res(18, 16) = 0;
  _res(19, 16) = 0;
  _res(20, 16) = 0;
  _res(21, 16) = 0;
  _res(22, 16) = 0;
  _res(0, 17) = P(0, 17) + P(1, 17) * _tmp5 + P(2, 17) * _tmp2 - P(9, 17) * dt;
  _res(1, 17) = P(0, 17) * _tmp13 + P(1, 17) - P(10, 17) * dt + P(2, 17) * _tmp16;
  _res(2, 17) = P(0, 17) * _tmp22 + P(1, 17) * _tmp23 - P(11, 17) * dt + P(2, 17);
  _res(3, 17) = P(0, 17) * _tmp63 + P(1, 17) * _tmp60 - P(12, 17) * _tmp50 - P(13, 17) * _tmp65 -
                P(14, 17) * _tmp67 + P(2, 17) * _tmp45 + P(3, 17);
  _res(4, 17) = P(0, 17) * _tmp91 + P(1, 17) * _tmp99 - P(12, 17) * _tmp100 - P(13, 17) * _tmp95 -
                P(14, 17) * _tmp96 + P(2, 17) * _tmp92 + P(4, 17);
  _res(5, 17) = P(0, 17) * _tmp115 + P(1, 17) * _tmp122 - P(12, 17) * _tmp123 -
                P(13, 17) * _tmp119 - P(14, 17) * _tmp117 + P(2, 17) * _tmp120 + P(5, 17);
  _res(6, 17) = P(3, 17) * dt + P(6, 17);
  _res(7, 17) = P(4, 17) * dt + P(7, 17);
  _res(8, 17) = P(5, 17) * dt + P(8, 17);
  _res(9, 17) = P(9, 17);
  _res(10, 17) = P(10, 17);
  _res(11, 17) = P(11, 17);
  _res(12, 17) = P(12, 17);
  _res(13, 17) = P(13, 17);
  _res(14, 17) = P(14, 17);
  _res(15, 17) = P(15, 17);
  _res(16, 17) = P(16, 17);
  _res(17, 17) = P(17, 17);
  _res(18, 17) = 0;
  _res(19, 17) = 0;
  _res(20, 17) = 0;
  _res(21, 17) = 0;
  _res(22, 17) = 0;
  _res(0, 18) = P(0, 18) + P(1, 18) * _tmp5 + P(2, 18) * _tmp2 - P(9, 18) * dt;
  _res(1, 18) = P(0, 18) * _tmp13 + P(1, 18) - P(10, 18) * dt + P(2, 18) * _tmp16;
  _res(2, 18) = P(0, 18) * _tmp22 + P(1, 18) * _tmp23 - P(11, 18) * dt + P(2, 18);
  _res(3, 18) = P(0, 18) * _tmp63 + P(1, 18) * _tmp60 - P(12, 18) * _tmp50 - P(13, 18) * _tmp65 -
                P(14, 18) * _tmp67 + P(2, 18) * _tmp45 + P(3, 18);
  _res(4, 18) = P(0, 18) * _tmp91 + P(1, 18) * _tmp99 - P(12, 18) * _tmp100 - P(13, 18) * _tmp95 -
                P(14, 18) * _tmp96 + P(2, 18) * _tmp92 + P(4, 18);
  _res(5, 18) = P(0, 18) * _tmp115 + P(1, 18) * _tmp122 - P(12, 18) * _tmp123 -
                P(13, 18) * _tmp119 - P(14, 18) * _tmp117 + P(2, 18) * _tmp120 + P(5, 18);
  _res(6, 18) = P(3, 18) * dt + P(6, 18);
  _res(7, 18) = P(4, 18) * dt + P(7, 18);
  _res(8, 18) = P(5, 18) * dt + P(8, 18);
  _res(9, 18) = P(9, 18);
  _res(10, 18) = P(10, 18);
  _res(11, 18) = P(11, 18);
  _res(12, 18) = P(12, 18);
  _res(13, 18) = P(13, 18);
  _res(14, 18) = P(14, 18);
  _res(15, 18) = P(15, 18);
  _res(16, 18) = P(16, 18);
  _res(17, 18) = P(17, 18);
  _res(18, 18) = P(18, 18);
  _res(19, 18) = 0;
  _res(20, 18) = 0;
  _res(21, 18) = 0;
  _res(22, 18) = 0;
  _res(0, 19) = P(0, 19) + P(1, 19) * _tmp5 + P(2, 19) * _tmp2 - P(9, 19) * dt;
  _res(1, 19) = P(0, 19) * _tmp13 + P(1, 19) - P(10, 19) * dt + P(2, 19) * _tmp16;
  _res(2, 19) = P(0, 19) * _tmp22 + P(1, 19) * _tmp23 - P(11, 19) * dt + P(2, 19);
  _res(3, 19) = P(0, 19) * _tmp63 + P(1, 19) * _tmp60 - P(12, 19) * _tmp50 - P(13, 19) * _tmp65 -
                P(14, 19) * _tmp67 + P(2, 19) * _tmp45 + P(3, 19);
  _res(4, 19) = P(0, 19) * _tmp91 + P(1, 19) * _tmp99 - P(12, 19) * _tmp100 - P(13, 19) * _tmp95 -
                P(14, 19) * _tmp96 + P(2, 19) * _tmp92 + P(4, 19);
  _res(5, 19) = P(0, 19) * _tmp115 + P(1, 19) * _tmp122 - P(12, 19) * _tmp123 -
                P(13, 19) * _tmp119 - P(14, 19) * _tmp117 + P(2, 19) * _tmp120 + P(5, 19);
  _res(6, 19) = P(3, 19) * dt + P(6, 19);
  _res(7, 19) = P(4, 19) * dt + P(7, 19);
  _res(8, 19) = P(5, 19) * dt + P(8, 19);
  _res(9, 19) = P(9, 19);
  _res(10, 19) = P(10, 19);
  _res(11, 19) = P(11, 19);
  _res(12, 19) = P(12, 19);
  _res(13, 19) = P(13, 19);
  _res(14, 19) = P(14, 19);
  _res(15, 19) = P(15, 19);
  _res(16, 19) = P(16, 19);
  _res(17, 19) = P(17, 19);
  _res(18, 19) = P(18, 19);
  _res(19, 19) = P(19, 19);
  _res(20, 19) = 0;
  _res(21, 19) = 0;
  _res(22, 19) = 0;
  _res(0, 20) = P(0, 20) + P(1, 20) * _tmp5 + P(2, 20) * _tmp2 - P(9, 20) * dt;
  _res(1, 20) = P(0, 20) * _tmp13 + P(1, 20) - P(10, 20) * dt + P(2, 20) * _tmp16;
  _res(2, 20) = P(0, 20) * _tmp22 + P(1, 20) * _tmp23 - P(11, 20) * dt + P(2, 20);
  _res(3, 20) = P(0, 20) * _tmp63 + P(1, 20) * _tmp60 - P(12, 20) * _tmp50 - P(13, 20) * _tmp65 -
                P(14, 20) * _tmp67 + P(2, 20) * _tmp45 + P(3, 20);
  _res(4, 20) = P(0, 20) * _tmp91 + P(1, 20) * _tmp99 - P(12, 20) * _tmp100 - P(13, 20) * _tmp95 -
                P(14, 20) * _tmp96 + P(2, 20) * _tmp92 + P(4, 20);
  _res(5, 20) = P(0, 20) * _tmp115 + P(1, 20) * _tmp122 - P(12, 20) * _tmp123 -
                P(13, 20) * _tmp119 - P(14, 20) * _tmp117 + P(2, 20) * _tmp120 + P(5, 20);
  _res(6, 20) = P(3, 20) * dt + P(6, 20);
  _res(7, 20) = P(4, 20) * dt + P(7, 20);
  _res(8, 20) = P(5, 20) * dt + P(8, 20);
  _res(9, 20) = P(9, 20);
  _res(10, 20) = P(10, 20);
  _res(11, 20) = P(11, 20);
  _res(12, 20) = P(12, 20);
  _res(13, 20) = P(13, 20);
  _res(14, 20) = P(14, 20);
  _res(15, 20) = P(15, 20);
  _res(16, 20) = P(16, 20);
  _res(17, 20) = P(17, 20);
  _res(18, 20) = P(18, 20);
  _res(19, 20) = P(19, 20);
  _res(20, 20) = P(20, 20);
  _res(21, 20) = 0;
  _res(22, 20) = 0;
  _res(0, 21) = P(0, 21) + P(1, 21) * _tmp5 + P(2, 21) * _tmp2 - P(9, 21) * dt;
  _res(1, 21) = P(0, 21) * _tmp13 + P(1, 21) - P(10, 21) * dt + P(2, 21) * _tmp16;
  _res(2, 21) = P(0, 21) * _tmp22 + P(1, 21) * _tmp23 - P(11, 21) * dt + P(2, 21);
  _res(3, 21) = P(0, 21) * _tmp63 + P(1, 21) * _tmp60 - P(12, 21) * _tmp50 - P(13, 21) * _tmp65 -
                P(14, 21) * _tmp67 + P(2, 21) * _tmp45 + P(3, 21);
  _res(4, 21) = P(0, 21) * _tmp91 + P(1, 21) * _tmp99 - P(12, 21) * _tmp100 - P(13, 21) * _tmp95 -
                P(14, 21) * _tmp96 + P(2, 21) * _tmp92 + P(4, 21);
  _res(5, 21) = P(0, 21) * _tmp115 + P(1, 21) * _tmp122 - P(12, 21) * _tmp123 -
                P(13, 21) * _tmp119 - P(14, 21) * _tmp117 + P(2, 21) * _tmp120 + P(5, 21);
  _res(6, 21) = P(3, 21) * dt + P(6, 21);
  _res(7, 21) = P(4, 21) * dt + P(7, 21);
  _res(8, 21) = P(5, 21) * dt + P(8, 21);
  _res(9, 21) = P(9, 21);
  _res(10, 21) = P(10, 21);
  _res(11, 21) = P(11, 21);
  _res(12, 21) = P(12, 21);
  _res(13, 21) = P(13, 21);
  _res(14, 21) = P(14, 21);
  _res(15, 21) = P(15, 21);
  _res(16, 21) = P(16, 21);
  _res(17, 21) = P(17, 21);
  _res(18, 21) = P(18, 21);
  _res(19, 21) = P(19, 21);
  _res(20, 21) = P(20, 21);
  _res(21, 21) = P(21, 21);
  _res(22, 21) = 0;
  _res(0, 22) = P(0, 22) + P(1, 22) * _tmp5 + P(2, 22) * _tmp2 - P(9, 22) * dt;
  _res(1, 22) = P(0, 22) * _tmp13 + P(1, 22) - P(10, 22) * dt + P(2, 22) * _tmp16;
  _res(2, 22) = P(0, 22) * _tmp22 + P(1, 22) * _tmp23 - P(11, 22) * dt + P(2, 22);
  _res(3, 22) = P(0, 22) * _tmp63 + P(1, 22) * _tmp60 - P(12, 22) * _tmp50 - P(13, 22) * _tmp65 -
                P(14, 22) * _tmp67 + P(2, 22) * _tmp45 + P(3, 22);
  _res(4, 22) = P(0, 22) * _tmp91 + P(1, 22) * _tmp99 - P(12, 22) * _tmp100 - P(13, 22) * _tmp95 -
                P(14, 22) * _tmp96 + P(2, 22) * _tmp92 + P(4, 22);
  _res(5, 22) = P(0, 22) * _tmp115 + P(1, 22) * _tmp122 - P(12, 22) * _tmp123 -
                P(13, 22) * _tmp119 - P(14, 22) * _tmp117 + P(2, 22) * _tmp120 + P(5, 22);
  _res(6, 22) = P(3, 22) * dt + P(6, 22);
  _res(7, 22) = P(4, 22) * dt + P(7, 22);
  _res(8, 22) = P(5, 22) * dt + P(8, 22);
  _res(9, 22) = P(9, 22);
  _res(10, 22) = P(10, 22);
  _res(11, 22) = P(11, 22);
  _res(12, 22) = P(12, 22);
  _res(13, 22) = P(13, 22);
  _res(14, 22) = P(14, 22);
  _res(15, 22) = P(15, 22);
  _res(16, 22) = P(16, 22);
  _res(17, 22) = P(17, 22);
  _res(18, 22) = P(18, 22);
  _res(19, 22) = P(19, 22);
  _res(20, 22) = P(20, 22);
  _res(21, 22) = P(21, 22);
  _res(22, 22) = P(22, 22);

  return _res;
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym