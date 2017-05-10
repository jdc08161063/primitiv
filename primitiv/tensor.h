#ifndef PRIMITIV_TENSOR_H_
#define PRIMITIV_TENSOR_H_

#include <memory>
#include <vector>
#include <primitiv/device.h>
#include <primitiv/shape.h>

namespace primitiv {

/**
 * Value with any dimensions.
 */
class Tensor {
  Tensor() = delete;

public:
  Tensor(const Tensor &) = delete;
  Tensor(Tensor &&);
  Tensor &operator=(const Tensor &) = delete;
  Tensor &operator=(Tensor &&);
  ~Tensor();

  /**
   * Creates a new uninitialized Tensor.
   * @param shape Shape of the new Tensor.
   * @param device Device object to manage internal memory.
   */
  Tensor(const Shape &shape, const std::shared_ptr<Device> &device);

  /**
   * Creates a new Tensor with specific values.
   * @param shape Shape of the new Tensor.
   * @param device Device object to manage internal memory.
   * @param data List of values to be set to each element.
   *             Each values should be arranged by the column-major order, and
   *             the batch size is assumed as the last dimension.
   */
  Tensor(
      const Shape &shape,
      const std::shared_ptr<Device> &device,
      const std::vector<float> &data);

  /**
   * Returns the shape of the Tensor.
   * @return Shape of the Tensor.
   */
  const Shape &shape() const { return shape_; }

  /**
   * Returns the Device object related to the internal memory.
   * @return Device object.
   */
  const std::shared_ptr<Device> &device() const { return device_; }


  /**
   * Returns the raw pointer of the internal memory.
   * @return Pointer of the internal memory.
   */
  void *data() { return data_; }

  /**
   * Returns a copied list of internal values.
   * @return List of copied values.
   */
  std::vector<float> to_vector() const;

private:
  Shape shape_;
  std::shared_ptr<Device> device_;
  void *data_;
};

}  // namespace primitiv

#endif  // PRIMITIV_TENSOR_H_
