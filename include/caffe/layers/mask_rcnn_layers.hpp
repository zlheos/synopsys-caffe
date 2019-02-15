// ------------------------------------------------------------------
// Mask R-CNN
// Copyright (c) 2015 Microsoft
// Licensed under The MIT License [see fast-rcnn/LICENSE for details]
// Written by Ross Girshick
// Modified by Jeremy Qiu
// ------------------------------------------------------------------

#ifndef CAFFE_MASK_RCNN_LAYERS_HPP_
#define CAFFE_MASK_RCNN_LAYERS_HPP_

#include <cfloat>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include <algorithm>
#include <stdlib.h>

#include "caffe/blob.hpp"
#include "caffe/common.hpp"
#include "caffe/layer.hpp"
#include "caffe/proto/caffe.pb.h"

#include "caffe/layers/loss_layer.hpp"

namespace caffe
{

/* ROIAlignLayer - Region of Interest Aligning & Pooling Layer
*/
template <typename Dtype>
class ROIAlignLayer : public Layer<Dtype>
{
public:
  explicit ROIAlignLayer(const LayerParameter &param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype> *> &bottom,
                          const vector<Blob<Dtype> *> &top);
  virtual void Reshape(const vector<Blob<Dtype> *> &bottom,
                       const vector<Blob<Dtype> *> &top);

  virtual inline const char *type() const { return "ROIAlign"; }

  virtual inline int ExactNumBottomBlobs() const { return 2; }
  //virtual inline int MaxBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }
  //virtual inline int MaxTopBlobs() const { return 1; }

protected:
  virtual void Forward_cpu(const vector<Blob<Dtype> *> &bottom,
                           const vector<Blob<Dtype> *> &top);
  virtual void Forward_gpu(const vector<Blob<Dtype> *> &bottom,
                           const vector<Blob<Dtype> *> &top);
  virtual void Backward_cpu(const vector<Blob<Dtype> *> &top,
                            const vector<bool> &propagate_down, const vector<Blob<Dtype> *> &bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype> *> &top,
                            const vector<bool> &propagate_down, const vector<Blob<Dtype> *> &bottom);

  int channels_;
  int height_;
  int width_;
  int pooled_height_;
  int pooled_width_;
  Dtype spatial_scale_;
  Blob<int> max_pts_;
  Blob<Dtype> max_mult_; //CUSTOMIZATION
};

} // namespace caffe

#endif // CAFFE_MASK_RCNN_LAYERS_HPP_
